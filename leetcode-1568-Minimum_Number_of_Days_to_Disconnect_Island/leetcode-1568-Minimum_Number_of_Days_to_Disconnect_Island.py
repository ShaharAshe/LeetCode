import copy
class Solution:
    def minDays(self, grid: list[list[int]]) -> int:
        new_grid = copy.deepcopy(grid)
        bfs_queue:list = []
        num_of_islands = 0
        num_of_cells = 0
        for cell_r in range(len(new_grid)):
            for cell_c in range(len(new_grid[cell_r])):
                if new_grid[cell_r][cell_c] == 1:
                    bfs_queue += [[cell_r, cell_c]]
                    new_grid[cell_r][cell_c] = 0
                    num_of_islands += 1
                    num_of_cells += 1
                while len(bfs_queue):
                    r = bfs_queue[0][0]
                    c = bfs_queue[0][1]
                    if r < len(new_grid)-1:
                        if new_grid[r+1][c] == 1:
                            bfs_queue += [[r+1, c]]
                            new_grid[r+1][c] = 0
                            num_of_cells += 1
                    if c < len(new_grid[cell_r])-1:
                        if new_grid[r][c+1] == 1:
                            bfs_queue += [[r, c+1]]
                            new_grid[r][c+1] = 0
                            num_of_cells += 1
                    if r > 0:
                        if new_grid[r-1][c] == 1:
                            bfs_queue += [[r-1, c]]
                            new_grid[r-1][c] = 0
                            num_of_cells += 1
                    if c > 0:
                        if new_grid[r][c-1] == 1:
                            bfs_queue += [[r, c-1]]
                            new_grid[r][c-1] = 0
                            num_of_cells += 1
                    bfs_queue = bfs_queue[1:]
        if num_of_islands != 1:
            return 0
        elif num_of_cells == 1 or num_of_cells == 3:
            return 1
        elif num_of_cells == 2:
            return 2
        
        for cell_r_i in range(len(grid)):
            for cell_c_i in range(len(grid[cell_r_i])):
                new_grid = copy.deepcopy(grid)
                new_grid[cell_r_i][cell_c_i] = 0
                num_of_islands = 0
                for cell_r in range(len(grid)):
                    for cell_c in range(len(grid[cell_r])):
                        if new_grid[cell_r][cell_c] == 1:
                            bfs_queue += [[cell_r, cell_c]]
                            new_grid[cell_r][cell_c] = 0
                            num_of_islands += 1
                        while len(bfs_queue):
                            r = bfs_queue[0][0]
                            c = bfs_queue[0][1]
                            if r < len(new_grid)-1:
                                if new_grid[r+1][c] == 1:
                                    bfs_queue += [[r+1, c]]
                                    new_grid[r+1][c] = 0
                            if c < len(new_grid[cell_r])-1:
                                if new_grid[r][c+1] == 1:
                                    bfs_queue += [[r, c+1]]
                                    new_grid[r][c+1] = 0
                            if r > 0:
                                if new_grid[r-1][c] == 1:
                                    bfs_queue += [[r-1, c]]
                                    new_grid[r-1][c] = 0
                            if c > 0:
                                if new_grid[r][c-1] == 1:
                                    bfs_queue += [[r, c-1]]
                                    new_grid[r][c-1] = 0
                            bfs_queue = bfs_queue[1:]
                if num_of_islands != 1 and num_of_islands!=0:
                    return 1
        return 2    



if __name__ == "__main__":
    # vec:list = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
    # vec:list = [[1,1]]
    # vec:list = [[1,0,0],[1,1,0],[1,0,0]]
    vec:list = [[1,1,0,1,1],[1,1,1,1,1],[1,1,0,1,1],[1,1,0,1,1]]
    res:Solution = Solution()

    print(res.minDays(vec))
