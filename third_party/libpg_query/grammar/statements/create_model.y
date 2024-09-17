/*****************************************************************************
 *
 *		QUERY :
 *				CREATE MODEL modelname
 *
 *****************************************************************************/
CreateModelStmt:
			CREATE_P OptTemp model_type_value MODEL qualified_name PATH SCONST model_on OUTPUT '(' with_result_col_list ')' opt_option
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$5->relpersistence = $2;
					n->model = $5;
					n->model_type = $3;
					n->model_path = $7;
					n->model_on = $8;
					n->result_set = $11;
					n->options = $13;
					n->ownerId = InvalidOid;
					n->onconflict = PG_ERROR_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
			| CREATE_P OptTemp model_type_value MODEL IF_P NOT EXISTS qualified_name PATH SCONST model_on OUTPUT '(' with_result_col_list ')' opt_option
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$8->relpersistence = $2;
					n->model = $8;
					n->model_type = $3;
					n->model_path = $10;
					n->model_on = $11;
					n->result_set = $14;
					n->options = $16;
					n->ownerId = InvalidOid;
					n->onconflict = PG_IGNORE_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
			| CREATE_P OR REPLACE OptTemp model_type_value MODEL qualified_name PATH SCONST model_on OUTPUT '(' with_result_col_list ')' opt_option
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$7->relpersistence = $4;
					n->model = $7;
					n->model_type = $5;
					n->model_path = $9;
					n->model_on = $10;
					n->result_set = $13;
					n->options = $15;
					n->ownerId = InvalidOid;
					n->onconflict = PG_REPLACE_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
		;
		
model_type_value:
			TABULAR 							{ $$ = 0; }
			| LLM 								{ $$ = 1; }
			| GNN 								{ $$ = 2; }
		;

model_on:
			ON TABLE qualified_name opt_feat_col_list
				{
					PGModelOn *n = makeNode(PGModelOn);
					n->rel_name = $3;
					n->rel_feat = $4;
					$$ = (PGNode *)n;
				}
			| ON feat_col_list
				{
					PGModelOn *n = makeNode(PGModelOn);
					n->rel_feat = $2;
					$$ = (PGNode *)n;
				}
			| ON NODES qualified_name opt_feat_col_list EDGES qualified_name opt_feat_col_list
				{
					PGModelOn *n = makeNode(PGModelOn);
					n->rel_name = $3;
					n->rel_feat = $4;
					n->opt_name = $6;
					n->opt_feat = $7;
					$$ = (PGNode *)n;
				}
		;

opt_feat_col_list:
			feat_col_list						{ $$ = $1; }
			| /* empty */						{ $$ = NULL; }	
		;

feat_col_list: 
			FEATURES '(' name_list_opt_comma ')'
				{
					PGPredictFeatExpr *n = makeNode(PGPredictFeatExpr);
					n->input_set = $3;
					$$ = (PGNode *) n;
				}
			| FEATURES '*' opt_except_list
				{
					PGPredictFeatExpr *n = makeNode(PGPredictFeatExpr);
					n->exclude_set = $3;
					$$ = (PGNode *) n;
				}
		;

with_result_col_list:
			result_col_list					{ $$ = $1; }
			| result_col_list ','					{ $$ = $1; }
			| /*EMPTY*/							{ $$ = NIL; }
		;

result_col_list:
			columnDef
				{
					$$ = list_make1($1);
				}
			| result_col_list ',' columnDef
				{
					$$ = lappend($1, $3);
				}
		;

opt_option:
            OPTIONS '{' dict_arguments_opt_comma '}'
			    { 
					$$ = $3; 
				}
            | /*EMPTY*/							{ $$ = NIL; }

