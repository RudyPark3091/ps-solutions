while True:
    n, *height_list = list(map(int, input().split(' ')))

    if n == 0:
        break

    height_list.append(0)
    stack = []
    max_area = 0
    for index, height in enumerate(height_list):
        # 이전 히스토그램의 높이가 지금 히스토그램보다 크면
        while stack and height_list[stack[-1]] > height:
            # 직사각형의 높이는 이전 히스토그램의 높이
            area_height = height_list[stack.pop()]
            # 너비는 스택에 넣기 시작한시점부터 지나온 히스토그램의 갯수
            area_width = index - stack[-1] - 1 if stack else index

            # 지금까지 계산한 최대넓이와 비교해서 최대값 갱신
            if max_area < area_height * area_width:
                max_area = area_height * area_width
        stack.append(index)
    print(max_area)
