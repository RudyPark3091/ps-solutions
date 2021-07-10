n, m = map(int, input().split())
white = ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
black = ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
wb_list = [white, black]

chess_list = []
for i in range(n):
    chess_list.append(input())

min_square = 9999
for i in range(m - 7):
    for j in range(n - 7):
        counter_white = 0
        counter_black = 0
        for js in range(j, j+8):
            for index, letter in enumerate(chess_list[js][i:i+8]):
                if letter != wb_list[js % 2][index]:
                    counter_white += 1
                if letter != wb_list[(js+1) % 2][index]:
                    counter_black += 1

        minvalue = min(counter_white, counter_black)
        if minvalue < min_square:
            min_square = minvalue

print(min_square)
