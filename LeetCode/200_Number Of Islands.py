class Solution:
    """1번
    def dfs(self, grid, x, y):
        if x<0 or x>=len(grid) or y<0 or y>=len(grid[0]):
            return False
        if grid[x][y] != '1':
            return False

        if grid[x][y] == '1':
            grid[x][y] = '0'
            self.dfs(grid, x+1, y)
            self.dfs(grid, x-1, y)
            self.dfs(grid, x, y+1)
            self.dfs(grid, x, y-1)
            return True

    def numIslands(self, grid: list[list[str]]) -> int:      
        result = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.dfs(grid, i,j)
                    result += 1
        return result
    """
    """2번(1번과 같은 풀이지만 중첩 함수 사용)
    def numIslands(self, grid: list[list[str]]) -> int: 
        def dfs(x, y):#중첩함수를 사용한 경우 : 함수 내에 위치한 또 다른 함수
                    #모든 함수의 변수를 쓸 수 있기에 grid를 파라미터로 넘기지 않아도 됨
                    #다만, 중첩함수 내에서 재할당을 하게 되면 (Ex) a = 'xx') 함수 내에서만 사용 가능한 로컬 변수로 선언되며 재할당된 값을 부모 함수에서는 반영되지 않음
            if x<0 or x>=len(grid) or y<0 or y>=len(grid[0]):
                return False
            if grid[x][y] != '1':
                return False

            if grid[x][y] == '1':
                grid[x][y] = '0'
                dfs(x+1, y)
                dfs(x-1, y)
                dfs(x, y+1)
                dfs(x, y-1)
                return True

        result = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    dfs(i,j)
                    result += 1
        return result
    """

    def numIslands(self, grid: list[list[str]]) -> int:
        if not grid:
            return 0
        
        m = len(grid)
        n = len(grid[0])
        sum = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    stack = list()
                    stack.append([i,j])
                    sum += 1
                    
                    while stack:
                        [p,q] = stack.pop()
                        
                        if p>=1 and grid[p-1][q] == '1':
                            stack.append([p-1,q])
                        if p<m-1 and grid[p+1][q] == '1':
                            stack.append([p+1,q])
                        if q>=1 and grid[p][q-1] == '1':
                            stack.append([p,q-1])
                        if q<n-1 and grid[p][q+1] == '1':
                            stack.append([p,q+1])
                        
                        grid[p][q] = '0'
        return sum

if __name__ == "__main__":
    s = Solution()
    print(s.numIslands(grid = [
                            ["1","1","1","1","0"],
                            ["1","1","0","1","0"],
                            ["1","1","0","0","0"],
                            ["0","0","0","0","0"]
                            ]))
    print(s.numIslands(grid = [
                            ["1","1","0","0","0"],
                            ["1","1","0","0","0"],
                            ["0","0","1","0","0"],
                            ["0","0","0","1","1"]
                            ]))