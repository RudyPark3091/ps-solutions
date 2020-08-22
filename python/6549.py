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


while True:
    n, *histogram = list(map(int, input().split()))
    if n == 0: break
    stack = []
    max = 0
    for i, h in enumerate(histogram):
        if not stack:
            stack.append((i, h))
        else:
            if stack[-1][1] <= h:
                stack.append((i, h))
            else:
                while stack and stack[-1][1] > h:
                    temp = stack.pop()
                    if not stack:
                        area = (i) * temp[1]
                    else:
                        area = (i - stack[-1][0] - 1) * temp[1]
                    if max < area: max = area
                stack.append((i, h))
    while stack:
        temp = stack.pop()
        if not stack:
            area = (temp[0] + 1) * temp[1]
        else:
            area = (temp[0] - stack[-1][0]) * temp[1]
        if max < area: max = area
    print(max)


# while True:
#     N, *l = list(map(int, input().split()))
#     l.append(0)
#     if N == 0:
#         break
#     s = []
#     a = 0
#     for i, h in enumerate(l):
#         while s and l[s[-1]] > h:
#             ih = l[s.pop()]
#
#             # s의 높이!
#             w = i-s[-1]-1 if s else i
#
#             # i에서부터 s의 top까지의 거리를 가로길이로 한다.
#             # w = i일때는 마지막일 때
#             if a < w * ih:
#                 a = w * ih
#         s.append(i)
#     print(a)
