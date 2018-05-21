//Jason Chen
//Jadchen 1467583
//PA3

import java.io.*;
import java.util.Scanner;

public class Sparse {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(args[0]));//open scanner
		PrintWriter out = new PrintWriter(new FileWriter(args[1]));//open writer

		Matrix A = null;//to record the A matrix
		Matrix B = null;//to record the B matrix

		while (in.hasNextInt()) {
			int size = in.nextInt();//Size is the first int
			int a = in.nextInt();//
			int b = in.nextInt();
			A = new Matrix(size);
			B = new Matrix(size);
			for (int i = 1; i <= a; i++) {//repeat the number of entry of Matrix a times
				int row = in.nextInt();
				int col = in.nextInt();
				double val = in.nextDouble();
				A.changeEntry(row, col, val);
			}
			for (int i = 1; i <= b; i++) {//repeat the number of entry of Matrix b times
				int row = in.nextInt();
				int col = in.nextInt();
				double val = in.nextDouble();
				B.changeEntry(row, col, val);
			}
		}
		in.close();

		out.println("A has" + " " + A.getNNZ() + " " + "non-zero entries:");
		out.println(A);
		out.println();

		out.println("B has" + " " + B.getNNZ() + " " + "non-zero entries:");
		out.println(B);
		out.println();

		out.println("(1.5)*A =");
		out.println(A.scalarMult(1.5));
		out.println();

		out.println("A+B =");
		out.println(A.add(B));
		out.println();

		out.println("A+A =");
		out.println(A.add(A));
		out.println();

		out.println("B-A =");
		out.println(B.sub(A));
		out.println();

		out.println("A-A =");
		out.println(A.sub(A));
		out.println();

		out.println("Transpose(A) =");
		out.println(A.transpose());
		out.println();

		out.println("A*B =");
		out.println(A.mult(B));
		out.println();

		out.println("B*B =");
		out.println(B.mult(B));
		out.println();
		out.close();
	}
}
