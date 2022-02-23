import java.util.*;

public class OpenChatRoom {
    public String[] solution(String[] record) {
        ArrayList<String> logList = new ArrayList<>();
        HashMap<String, String> user = new HashMap<>();

        for(String r : record){
            String[] arr = r.split(" ");

            if(arr[0].equals("Enter")){
                user.put(arr[1], arr[2]);
                logList.add(arr[1]);
                logList.add("님이 들어왔습니다.");
            }else if(arr[0].equals("Leave")){
                logList.add(arr[1]);
                logList.add("님이 나갔습니다.");
            }else if(arr[0].equals("Change")){
                user.put(arr[1], arr[2]);
            }
        }

        String[] answer = new String[logList.size()/2];

        for(int i=0; i<logList.size(); i+=2){
            answer[i/2] = user.get(logList.get(i)) + logList.get(i+1);
        }
        return answer;
    }

    public static void main(String[] args) {
        OpenChatRoom s = new OpenChatRoom();
        String[] record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        
        String[] result = s.solution(record);
        for(String re : result){
            System.out.println(re);
        }
    }
}
