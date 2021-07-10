import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static boolean[][] graph = new boolean[1001][1001];
	static boolean[] visited = new boolean[1001];
	static Queue<Integer> q = new LinkedList<>();

	static int n, m, v;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		v = sc.nextInt();

		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			graph[a][b] = true;
			graph[b][a] = true;
		}

		dfs(v);
		visited = new boolean[1001];
		System.out.println();

		bfs(v);
		sc.close();
	}

	static void dfs(int num) {
		System.out.printf("%d ", num);
		visited[num] = true;

		for (int i = 1; i <= n; i++) {
			if (!visited[i] && graph[num][i]) {
				dfs(i);
			}
		}
	}

	static void bfs(int num) {
		visited[num] = true;
		q.add(num);

		while (!q.isEmpty()) {
			int p = q.poll();
			System.out.printf("%d ", p);

			for (int i = 1; i <= n; i++) {
				if (!visited[i] && graph[p][i]) {
					q.add(i);
					visited[i] = true;
				}
			}
		}
	}
}
