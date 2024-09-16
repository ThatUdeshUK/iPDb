/*****************************************************************************
 *
 *		QUERY :
 *				CREATE MODEL modelname
 *				ALTER MODEL modelname
 *
 *****************************************************************************/
CreateModelStmt:
			CREATE_P OptTemp MODEL qualified_name '(' model_type_wgnn_value SCONST ')'
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$4->relpersistence = $2;
					n->model = $4;
					n->model_type = $6;
					n->model_path = $7;
					n->ownerId = InvalidOid;
					n->onconflict = PG_ERROR_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
			| CREATE_P OptTemp MODEL IF_P NOT EXISTS qualified_name '(' model_type_wgnn_value SCONST ')'
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$7->relpersistence = $2;
					n->model = $7;
					n->model_type = $9;
					n->model_path = $10;
					n->ownerId = InvalidOid;
					n->onconflict = PG_IGNORE_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
			| CREATE_P OR REPLACE OptTemp MODEL qualified_name '(' model_type_wgnn_value SCONST ')'
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$6->relpersistence = $4;
					n->model = $6;
					n->model_type = $8;
					n->model_path = $9;
					n->ownerId = InvalidOid;
					n->onconflict = PG_REPLACE_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
		;
		
model_type_wgnn_value:
			TABULAR 							{ $$ = 0; }
			| LLM 								{ $$ = 1; }
			| GNN 								{ $$ = 2; }
		;
