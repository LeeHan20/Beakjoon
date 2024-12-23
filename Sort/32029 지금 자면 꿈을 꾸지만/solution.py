N, A, B = map(int, input().split())
deadlines = list(map(int, input().split()))

#N, A, B = 4, 30, 3
#deadlines = [70, 75, 95, 105]



def max_completed_tasks(N, A, B, deadlines):
    deadlines.sort()

    max_tasks = 0

    for X in range(A):
        reduced_time = A - X
        if reduced_time <= 0:
            continue

        time_elapsed = B * X
        completed_tasks = 0

        for deadline in deadlines:
            if time_elapsed + reduced_time <= deadline:
                time_elapsed += reduced_time
                completed_tasks += 1

        max_tasks = max(max_tasks, completed_tasks)

    for X in range(A):
        reduced_time = A - X
        if reduced_time <= 0:
            continue

        for k in range(N):
            time_elapsed = 0
            completed_tasks = 0

            for i in range(k):
                if time_elapsed + A <= deadlines[i]:
                    time_elapsed += A
                    completed_tasks += 1

            time_elapsed += B * X

            for j in range(k, N):
                if time_elapsed + reduced_time <= deadlines[j]:
                    time_elapsed += reduced_time
                    completed_tasks += 1

            max_tasks = max(max_tasks, completed_tasks)

    return max_tasks

result = max_completed_tasks(N, A, B, deadlines)
print(result)
