/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listasalgoritmos;

import java.util.Scanner;

/**
 *
 * @author Matheus Alves
 */
public class Lista6 {
	static int[][][] mm;
	static int[][][] dp;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int m = in.nextInt(), n = in.nextInt(), s = in.nextInt(), fi = in.nextInt(), fj = in.nextInt(), fk = in.nextInt();
		mm = new int[m][n][s];
		dp = new int[m][n][s];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < s; k++) {
					mm[i][j][k] = in.nextInt();
					dp[i][j][k] = -1;
				}
			}
		}
		int p = in.nextInt();
		for (int i = 0; i < p; i++) {
			int ii = in.nextInt(), j = in.nextInt(), k = in.nextInt();
			System.out.println(maxPont(ii, j, k, fi, fj, fk, n, s));
		}
	}

	public static int maxPont(int i, int j, int k, int fi, int fj, int fk, int n, int s) {
		if(i < 0 || j >= n || k >= s) {
			return Integer.MIN_VALUE;
		}
		if(dp[i][j][k] != -1) {
			return dp[i][j][k];
		}

		if(fi == i && fj == j && fk == k) {
			return mm[i][j][k];
		}
		else {
			dp[i][j][k] = max(maxPont(i - 1, j, k, fi, fj, fk, n, s), maxPont(i, j + 1, k, fi, fj, fk, n, s), maxPont(i, j, k + 1, fi, fj, fk, n, s)) + mm[i][j][k];
			return dp[i][j][k];
		}
	}

	public static int max(int x, int y, int z) {
		return (x > y) ? ((x > z) ? x : z)
				: ((y > z) ? y : z);
	}
}
