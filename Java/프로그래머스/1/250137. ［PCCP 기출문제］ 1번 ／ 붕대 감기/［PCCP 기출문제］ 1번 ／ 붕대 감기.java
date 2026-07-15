class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int currentHealth = health;

        int castingTime = bandage[0];
        int heal = bandage[1];
        int bonusHeal = bandage[2];

        int attackIdx = 0;
        int streak = 0;

        int maxTime = attacks[attacks.length - 1][0];

        for (int time = 1; time <= maxTime; time++) {

            if (attackIdx < attacks.length &&
                attacks[attackIdx][0] == time) {

                currentHealth -= attacks[attackIdx][1];
                streak = 0;

                if (currentHealth <= 0) {
                    return -1;
                }

                attackIdx++;
            } else {
                streak++;

                currentHealth = Math.min(
                    health,
                    currentHealth + heal
                );

                if (streak == castingTime) {
                    currentHealth = Math.min(
                        health,
                        currentHealth + bonusHeal
                    );

                    streak = 0;
                }
            }
        }

        return currentHealth;
    }
}