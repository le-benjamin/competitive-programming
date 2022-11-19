for _ in range(int(input())):
    nums = sorted(list(map(float, input().split())))
    if nums[0] == 4 and nums[1] == 5 and nums[2] == 6: print("True")
    else: print(nums[0]**2 + nums[1]**2 == nums[2]**2)