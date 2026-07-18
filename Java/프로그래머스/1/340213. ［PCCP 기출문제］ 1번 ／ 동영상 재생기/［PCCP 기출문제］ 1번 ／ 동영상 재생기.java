class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        String[] parts = video_len.split(":");
        
        int minute = Integer.parseInt(parts[0]);
        int second = Integer.parseInt(parts[1]);
        
        int video = minute * 60 + second;
        
        parts = pos.split(":");
        
        minute = Integer.parseInt(parts[0]);
        second = Integer.parseInt(parts[1]);
        
        int now = minute * 60 + second;
        
        parts = op_start.split(":");
        
        minute = Integer.parseInt(parts[0]);
        second = Integer.parseInt(parts[1]);
        
        int start = minute * 60 + second;
        
        parts = op_end.split(":");
        
        minute = Integer.parseInt(parts[0]);
        second = Integer.parseInt(parts[1]);
        
        int end = minute * 60 + second;
        
        for(int i = 0; i < commands.length; i++)
        {
            if(now >= start && now <= end)
            {
                now = end;
            }
            
            if(commands[i].equals("next"))
            {
                now = Math.min(now + 10, video);
            }
            else if(commands[i].equals("prev"))
            {
                now = Math.max(now - 10, 0);
            }
        }
        
        if(now >= start && now <= end)
        {
            now = end;
        }
        
        answer = String.format("%02d:%02d", now / 60, now % 60);
        
        return answer;
    }
}