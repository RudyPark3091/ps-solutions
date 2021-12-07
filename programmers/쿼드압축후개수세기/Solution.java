class Solution {
    public static void solve(int[][] arr, int n, int x, int y) {
        int val = arr[x][y];
        boolean flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[x + i][y + j] != val) flag = true;
            }
        }

        if (n != 1 && !flag) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[x + i][y + j] = -1;
                }
            }
            arr[x][y] = val;
            return;
        }

        int nn = n / 2;
        solve(arr, nn, x, y);
        solve(arr, nn, x + nn, y);
        solve(arr, nn, x, y + nn);
        solve(arr, nn, x + nn, y + nn);
    }

    public static int count(int[][] arr, int x) {
        int ret = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                if (arr[i][j] == x) ret += 1;
            }
        }
        return ret;
    }

    public static int[] solution(int[][] arr) {
        int n = arr.length;
        solve(arr, n, 0, 0);

        int zeros = count(arr, 0);
        int ones = count(arr, 1);
        int[] answer = {zeros, ones};
        return answer;
    }

    public static void main(String[] args) throws Exception {
        int[][] tc1 = {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}};
        int[] sol1 = solution(tc1);
        if (sol1[0] != 4 || sol1[1] != 9) {
            throw new Exception("Error on tc 1");
        }

        int[][] tc2 = {
                {1, 1, 1, 1, 1, 1, 1, 1},
                {0, 1, 1, 1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1, 1, 1, 1},
                {0, 1, 0, 0, 1, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 1, 1, 1, 1},
        };
        int[] sol2 = solution(tc2);
        if (sol2[0] != 10 || sol2[1] != 15) {
            throw new Exception("Error on tc 2");
        }
    }
}
