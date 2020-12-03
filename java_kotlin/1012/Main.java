import java.util.Scanner;

public class Main {
	static int t, n, m, k;
	static boolean[][] graph = new boolean[50][50];
	static int[][] moves = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		t = sc.nextInt();
		for (int tt = 0; tt < t; tt++) {
			int res = 0;
			input();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (solve(i, j)) res++;
				}
			}

			System.out.println(res);
		}
	}

	static void input() {
		int a, b;
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		for (int i = 0; i < k; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			graph[a][b] = true;
		}
	}

	static boolean solve(int dx, int dy) {
		boolean bdry = 0 <= dx && dx < n && 0 <= dy && dy < m;
		if (!bdry) return false;

		if (graph[dx][dy]) {
			graph[dx][dy] = false;

			for (int i = 0; i < 4; i++) {
				solve(dx + moves[i][0], dy + moves[i][1]);
			}
			return true;
		}

		return false;
	}
}
