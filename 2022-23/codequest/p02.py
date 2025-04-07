tc = int(input())
for _ in range(tc):
    a, b = map(int, input().split())
    if a==b:
        print("Cassowary Craft and Lead Balloons Ltd sold the same number of aircraft")
    if a > b:
        print(f"Cassowary Craft sold {a-b} more aircraft")
    if b > a:
        print(f"Lead Balloons Ltd sold {b-a} more aircraft")
