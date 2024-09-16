/*****************************************************************************
 *
 *		QUERY :
 *				CREATE MODEL modelname
 *				ALTER MODEL modelname
 *
 *****************************************************************************/
CreateModelStmt:
			CREATE_P OptTemp model_type_value MODEL qualified_name PATH SCONST OUTPUT '(' with_result_col_list ')'
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$5->relpersistence = $2;
					n->model = $5;
					n->model_type = $3;
					n->model_path = $7;
					n->result_set = $10;
					n->ownerId = InvalidOid;
					n->onconflict = PG_ERROR_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
			| CREATE_P OptTemp model_type_value MODEL IF_P NOT EXISTS qualified_name PATH SCONST OUTPUT '(' with_result_col_list ')'
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$8->relpersistence = $2;
					n->model = $8;
					n->model_type = $3;
					n->model_path = $10;
					n->result_set = $13;
					n->ownerId = InvalidOid;
					n->onconflict = PG_IGNORE_ON_CONFLICT;
					$$ = (PGNode *)n;
				}
			| CREATE_P OR REPLACE OptTemp model_type_value MODEL qualified_name PATH SCONST OUTPUT '(' with_result_col_list ')'
				{
					PGCreateModelStmt *n = makeNode(PGCreateModelStmt);
					$7->relpersistence = $4;
					n->model = $7;
					n->model_type = $5;
					n->model_path = $9;
					n->result_set = $12;
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
