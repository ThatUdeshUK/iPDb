# DuckML

Experimental in-database LLM and deep-learning inference via native relational prediction operator. Built on top of a high-performance analytical database system, DuckDB. 

##  Building the Platform

You can get an up and running instance of `duckml` with either **Building from the source** or **Building with Docker**. 

### From the source

#### Step 1.1 - Prerequisite (Setup ONNX)

> This step is optional if you are only inferencing with LLMs (via API or local models).

First, configure the ONNX runtime library which we'll use for pre-trained models stored in `.onnx` format. You have multiple options to get an up and running instance of ONNX runtime library.

##### Build from stratch

Detailed instructions are available here [https://onnxruntime.ai/docs/build/inferencing.html](https://onnxruntime.ai/docs/build/inferencing.html).

##### Fetch a release binary

Download and extract a compatible release for your development platform from the `onnxruntime` GitHub [releases](https://github.com/microsoft/onnxruntime/releases/tag/v1.19.2).  

> Above link directs to the version `1.19.2` instead of the latest version as this is the version tested to work (on `linux-amd64`).

For both of the above options, set the ONNX runtime installed path as a env variable.

```bash
export ONNX_INSTALL_PREFIX=<onnx_runtime_installed_path>
```

#### Step 1.2 - Prerequisite (llama.cpp)

> This step is optional if you are only inferencing with pre-trained ONNX models.

First, fetch and build the `llama.cpp` library which we'll use for inferencing local large language models. You have multiple options to get an up and running instance of the `llama.cpp` library.

##### Build from stratch

Clone the `llama.cpp` repository.

```bash
git clone https://github.com/ggml-org/llama.cpp
cd llama.cpp
```

Build for the project using CMake (CPU build).

```bash
cmake -B build
cmake --build build --config Release -j 8
```

> `Release` builds prefered to achive the best inference performance.

Please refer to the detailed building guide [here](https://github.com/ggml-org/llama.cpp/blob/master/docs/build.md) in the `llama.cpp` repository for other backend (i.e. GPU), debug builds and trobleshooting.

Set the `llama.cpp` installed path as a env variable.

```bash
export LIBLLAMA_INSTALL_PREFIX="<llama_cpp_repo>/build"
```

#### Step 2 - Build our duckml instance

`duckdb` use a `make` script for the builds. We have extended that with additional parameters to configure `duckml`.

```
make debug GEN=ninja -j12 CORE_EXTENSIONS='httpfs' ENABLE_PREDICT=1 PREDICTOR_IMPL=llama_cpp ENABLE_LLM_API=True DISABLE_SANITIZER=1
```

##### Build Options

- `GEN=ninja -j12` (optional, drop if don't have ninja setup) use the ninja for build parallelization (w/ -j12 for 12 workers).
- `CORE_EXTENSIONS='httpfs'` enable the `httpfs` extension used for `https` communitation for API LLM calls.
- `ENABLE_PREDICT=1` enables the ML extension.
- `PREDICTOR_IMPL=onnx` choose the internal ML platform. Available options,
  -  `onnx` - Use ONNX Runtime to infer pre-trained `.onnx` models (Step 1.1 required).
  -  `llama_cpp` - Use llama.cpp to infer LLMs in `GGUF` format or use OpenAI models via the network (Step 1.2 required).
- `ENABLE_LLM_API=1` Enable LLM calling with OpenAI API compatible APIs.

> Previously available `torchscript` to infer pre-trained `pytorch` models exported with TorchScript is \[DEPRECATED\] and is not supported. 

##### API LLM Calling

Majority of publicly available remote LLMs requires an API key from the respective developer to use it's capabilities. Please, aqquire the respective key and set in the `env` variable as follows so that `DuckML` can indentify it before inference.

```bash
export OPENAI_API_KEY="<api_key>"
```

> Add the above in shell config file, i.e., `.bashrc` for permenant availability.

### With Docker

> Currently Docker script is written build only for ONNX model support. Please build from scratch to build for LLM inference.

Make sure Docker is set up correctly.

Clone the `duckml` repository. It should include a `Dockerfile` and a `.dockerignore`.

Build the Docker image by running (we'll create a image named `duckml`).

```bash
docker build -t duckml
```

Run the Docker image:

```bash
docker run -it -v <absolute_path_to_data_repo>:/data --name=”duckml_container” duckml /bin/bash
```

For subsequent runs, you can just spin up the stopped container using the name of the container.

```bash
docker start -ai duckml_container
```

> Both of the above commands will open an interactive shell in the Docker container. Here, we mount a data directory where we will be storing the pre-trained models. If you want just to see if the DuckML works, run the about command without `-v <absolute_path_to_mldb_repo>:/data`.

Run duckdb:
```bash
./build/debug/duckdb <your_database>
```

## Getting Started

Once you have a working DuckML instance, you can experiment with SQL queries that are capable of in-database inference.

### Simple Example

Within the duckdb shell,

- Create and populate tables with feature data (say, iris data).
-  Upload the model to the database via the `CREATE MODEL` statement.
	 ```sql
	 CREATE TABULAR MODEL iris_cls PATH `<model_path>` ON TABLE iris OUTPUT (class INTEGER); 
	 ```
-  Run a prediction query.
	```
	SELECT * FROM PREDICT(iris_cls, iris) AS p WHERE p.class = 2;
	```

Syntax tree and examples of both `CREATE MODEL` and `PREDICT` statements are available [here](https://drive.google.com/file/d/1j1qS_mJbFlXFbnh4ZLTtmB_KPRfZKG3u/view?usp=sharing) (opened via draw.io). 

Refer to additional examples and experiments in this [repository](https://github.com/ThatUdeshUK/mldb).

### Semantive Predicate with Remote LLM

Make sure you have build `DuckML` with options that enable remote LLM calling,

- `CORE_EXTENSIONS='httpfs'`
- `ENABLE_PREDICT=1`
- `PREDICTOR_IMPL=llama_cpp`
- `ENABLE_LLM_API=1`

Additionally, make sure `OPENAI_API_KEY` environment variable is set with the LLMs API key correctly.

Within the duckdb shell,

- Create and populate tables with data (say, a `job` table with `description` column containing a job listing document).
-  Upload the model to the database via the `CREATE MODEL` statement.
	 ```sql
	 CREATE LLM MODEL o4_mini PATH 'o4-mini' ON PROMPT API 'https://api.openai.com'; 
	 ```
	 
Notice that, `PATH` accepts the model name accepted by the API (e.g., `o4-mini`, `gpt-4.1`).

Furthermore, the model is uploaded as `ON PROMPT`, this results in the the query execution pipeline infering the input/output columns to the LLM from the prompt during the query execution.

Additionally, user should set `API` to the base url of the respective LLM. 

-  Run a prediction query.
	```sql
	SELECT * FROM PREDICT(o4_mini, PROMPT 'extract the {s:location} and {d:salary} for job {description}', job);
	```

Here, notice that we have an additional `PROMPT` clause within the `PREDICT` statement. Inside the prompt, user can define input columns by mentioning each column with braces, i.e., `{column}` (e.g., `{descrtiption}` in the above query). Similarly, user can define the output columns with braces in the format, `{data_type:column_name}` (e.g., `{s:location}` returns a `VARCHAR` column with location and `{d:salary}` returns a `INTEGER` column with salary).

## Additional Resources

- More details on building DuckDB from source is [here](https://duckdb.org/docs/stable/dev/building/overview).
- Follow the LibTorch tutorial on native model inference.
	- If you are new to deep-learning inference, start with beginner-friendly Python-based training and inference examples [here](https://pytorch.org/tutorials/beginner/basics/quickstart_tutorial.html).
	- Introduction to native C++ model exporting and inference with TorchScript is available [here](https://pytorch.org/tutorials/advanced/cpp_export.html). The most feature-rich version of DuckML is implemented via the ONNX runtime instead of LibTorch, but this guide is far better than any ONNX examples can offer (the concepts are the same).
- The high-level duckdb execution model is explained [in the official documentation](https://duckdb.org/docs/internals/overview) and these [slides](https://15721.courses.cs.cmu.edu/spring2023/slides/22-duckdb.pdf).
- Read the source for the implementation of DuckML. **Extensive documentation of this extension is WIP.**

## Data Platforms and Runtimes

Native relational prediction operator is realized using following systems and frameworks.

- DuckDB (1.3.0)- Relational Database [https://duckdb.org](https://duckdb.org/)
- ONNX Runtime (1.19) - Efficient generalizable deep learning runtime [https://onnx.ai](https://onnx.ai/)
- llama.cpp (latest) - Local LLM inference  [https://github.com/ggml-org/llama.cpp](https://github.com/ggml-org/llama.cpp)

## DuckDB

Please refer to the Official DuckDB repository for documentation of the base source code ([https://github.com/duckdb/duckdb](https://github.com/duckdb/duckdb)).
