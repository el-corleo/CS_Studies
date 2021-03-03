/*
Show functionality of different operators
*/
import operators.*;

public class Main
{
	public static void main(String[] args)
	{
		ArithmeticOperators arOp = new ArithmeticOperators();
		arOp.addOps();
		arOp.subOps();
		arOp.multDivOps();
		arOp.modOps();
		
		EqualityOperators eqOp = new EqualityOperators();
		eqOp.eqOps();
		eqOp.nonEqOps();
		
		RelationalOperators reOp = new RelationalOperators();
		reOp.ltOps();
		reOp.gtOps();
		
		LogicalOperators loOp = new LogicalOperators();
		loOp.logOps();
	}
}