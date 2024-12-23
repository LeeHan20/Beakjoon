from collections import Counter

def make_input():
    n, m, k = map(int, input().split())
    #n, m, k = 4, 6, 2
    #n, m, k = 2, 2, 1
    matrix = [list(input().rstrip()) for _ in range(n)]
    #matrix = [  ["A","B","C","B","A","B"],["B","B","A","C","C","A"],["B","P","A","Z","B","B"],["B","B","A","A","B","B"]  ]
    #matrix = [  "AB","QB","PS","EW","WQ","QA"  ]
    return n, m, k, matrix

def devide_into_kk(n, m, k, matrix):
    new_matrix = []
    for i in range(0, n, k):
        for j in range(0, m, k):
            inlist = []
            for a in range(k):
                for x in range(k):
                    inlist.append(matrix[i+a][j+x])
            new_matrix.append(inlist)
    return new_matrix

def find_alpha_and_make_matrix(k, matrix):
    count_similarity = k**2
    new_matrix = matrix[:]
    for i in range(k**2):
        column = [new_matrix[j][i] for j in range(len(new_matrix))]
        most_fre_alpha, freq = Counter(column).most_common(1)[0]
        count_similarity += freq - 1
        for j in range(len(new_matrix)):
            new_matrix[j][i] = most_fre_alpha
    return new_matrix[0], count_similarity

def print_min_tile(n, m, k, one_min_tile):
    one_min_tile = "".join(one_min_tile)
    restore = [one_min_tile[i*k:i*k+k] for i in range(k)]
    cal = n // k
    row = m // k
    new_restore = [i * row for i in restore]
    for _ in range(cal):
        for i in range(len(new_restore)):
            print(new_restore[i])

def main():
    n, m, k, matrix = make_input()
    new_matrix = devide_into_kk(n, m, k, matrix)
    one_min_tile, count_similarity = find_alpha_and_make_matrix(k, new_matrix)
    min_tile_change = n * m - count_similarity
    print(min_tile_change)
    print_min_tile(n, m, k, one_min_tile)

main()

