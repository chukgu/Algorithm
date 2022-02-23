public class SkillTree {
    public int solution(String skill, String[] skill_trees) {
        int arr_len = skill_trees.length;
        int s_len = skill.length();
        int answer = arr_len;

        for(int i=0; i<arr_len; i++){
            int prev = skill_trees[i].indexOf(skill.charAt(0));

            for(int j=1; j<s_len; j++){
                int idx = skill_trees[i].indexOf(skill.charAt(j));
                if(prev == -1 && idx > -1){
                    answer--;
                    break;
                }
                if(idx > -1 && idx < prev){
                    answer--;
                    break;
                }
                prev = idx;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        SkillTree s = new SkillTree();
        String[] b = {"BACDE", "CBADF", "AECB", "BDA"};
        System.out.println(s.solution("CBD", b));
    }
}