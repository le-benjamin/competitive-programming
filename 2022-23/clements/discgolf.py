pars = []
for i in range(3):
    input()
    pars.append(list(map(int, input().split())))
        
for _ in range(int(input())):
    p, ap, bp = [0, 0, 0]
    arr = input().split()
    name = arr[0]
    
    course_num = 0
    if name == 'B': course_num = 1
    elif name == 'C': course_num = 2
    
    scores = list(map(int, arr[1:]))
    for i, x in enumerate(scores):
        if (x == pars[course_num][i]): p += 1
        if (x < pars[course_num][i]): bp += 1
        if (x > pars[course_num][i]): ap += 1
            
    if name == 'A': print("AUSTIN_RIDGE_BIBLE_CHURCH")
    if name == 'B': print("BRUSHY_CREEK_CAT_HOLLOW")
    if name == 'C': print("CEDAR_VALLEY_MIDDLE_SCHOOL")
    
    course_total = sum(pars[course_num])
    score = sum(scores)
    print(f"COURSE TOTAL = {course_total}")
    print(f"SCORE = {score}")
    print(f"PARS = {p}")
    print(f"ABOVE PARS = {ap}")
    print(f"BELOW PARS = {bp}")
    print(f"OVERALL RESULT: {'PAR' if score == course_total else 'BELOW PAR' if score < course_total else 'ABOVE PAR'}")
    print()



    