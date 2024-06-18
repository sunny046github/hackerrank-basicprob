import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		// StringTokenizer tok = new StringTokenizer(in.readLine());
		int t = 1;
		for (int i = 0; i < t; i++) {
			oneTest(in);
		}

	}

	private static void oneTest(BufferedReader in) throws IOException {
		StringTokenizer tok = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int m = Integer.parseInt(tok.nextToken());

		int[][] graph = readGraph(in, n, m);
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][k] == -1 || graph[k][j] == -1)
						continue;
					if (graph[i][j] == -1
							|| graph[i][j] > graph[i][k] + graph[k][j]) {
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}

		int q = Integer.parseInt(in.readLine());
		for (int i = 0; i < q; i++) {
			tok = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(tok.nextToken()) - 1;
			int b = Integer.parseInt(tok.nextToken()) - 1;
			System.out.println(graph[a][b]);
		}
	}

	private static int[][] readGraph(BufferedReader in, int n, int m)
			throws IOException {
		int[][] res = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(res[i], -1);
			res[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			StringTokenizer tok = new StringTokenizer(in.readLine());

			int a = Integer.parseInt(tok.nextToken()) - 1;
			int b = Integer.parseInt(tok.nextToken()) - 1;
			int w = Integer.parseInt(tok.nextToken());

			res[a][b] = w;

		}
		return res;
	}

}
