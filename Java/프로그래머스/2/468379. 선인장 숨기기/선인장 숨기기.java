class Solution {
    public int[] solution(int m, int n, int h, int w, int[][] drops) {
        int[] answer = {0, 0};
        int[][] farm = new int[m][n];
        
        int INF = drops.length + 1;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                farm[i][j] = INF;
            }
        }
        
        for(int i = 0; i < drops.length; i++)
        {
            int x = drops[i][0];
            int y = drops[i][1];
            
            if(farm[x][y] > i + 1)
                farm[x][y] = i + 1;
        }
        
        int[][] row = new int[m][n - w + 1];
        
        for(int i = 0; i < m; i++)
        {
            java.util.ArrayDeque<Integer> q = new java.util.ArrayDeque<>();
            
            for(int j = 0; j < n; j++)
            {
                while(!q.isEmpty() && q.peekFirst() <= j - w)
                {
                    q.pollFirst();
                }
                
                while(!q.isEmpty() && farm[i][q.peekLast()] >= farm[i][j])
                {
                    q.pollLast();
                }
                
                q.offerLast(j);
                
                if(j >= w - 1)
                {
                    row[i][j - w + 1] = farm[i][q.peekFirst()];
                }
            }
        }
        
        int ansidx = -1;
        
        for(int j = 0; j < n - w + 1; j++)
        {
            java.util.ArrayDeque<Integer> q = new java.util.ArrayDeque<>();
            
            for(int i = 0; i < m; i++)
            {
                while(!q.isEmpty() && q.peekFirst() <= i - h)
                {
                    q.pollFirst();
                }
                
                while(!q.isEmpty() && row[q.peekLast()][j] >= row[i][j])
                {
                    q.pollLast();
                }
                
                q.offerLast(i);
                
                if(i >= h - 1)
                {
                    int x = i - h + 1;
                    int y = j;
                    int mn = row[q.peekFirst()][j];
                    
                    if(ansidx < mn || ansidx == mn && (x < answer[0] || x == answer[0] && y < answer[1]))
                    {
                        answer[0] = x;
                        answer[1] = y;
                        ansidx = mn;
                    }
                }
            }
        }
        
        return answer;
    }
}