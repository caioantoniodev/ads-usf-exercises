package main;

import main.entity.PersonVote;
import main.exception.BusinnesException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Boolean.TRUE;

public class NetPromoterScore {

    /* USE CASE
     * O percentual de respostas iguais a Promotores;
     * O percentual de respostas iguais a Detratores;
     * O percentual de respostas iguais a Passivas ou Neutras;
     * A média de idade dos respondentes Promotores
     */

    public static void main(String[] args) throws IOException {
        List<PersonVote> promoters = new ArrayList<>();
        List<PersonVote> passives = new ArrayList<>();
        List<PersonVote> detractors = new ArrayList<>();

        final int TOTAL_PERSON_VOTES = 3;

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < TOTAL_PERSON_VOTES; i++) {

            System.out.print("Entre com a idade: ");
            int age = Integer.parseInt(bufferedReader.readLine().trim());
            validate(age <= 0, "Please enter a valid age!");

            System.out.print("Entre com sua nota: ");
            int score = Integer.parseInt(bufferedReader.readLine().trim());
            validate(score < 0 || score > 10, "Please enter a valid score!");

            if (score >= 9) {
                var personVote = buildPersonVote(score, age);
                promoters.add(personVote);
            } else if  (score >= 7) {
                var personVote = buildPersonVote(score, age);
                passives.add(personVote);
            } else {
                var personVote = buildPersonVote(score, age);
                detractors.add(personVote);
            }
        }

        System.out.println("Percentual de Detratores "
                .concat(calculatePercentage(detractors, TOTAL_PERSON_VOTES)));

        System.out.println("Percentual de Passivos ou Neutros "
                .concat(calculatePercentage(passives, TOTAL_PERSON_VOTES)));

        System.out.println("Percentual de Promotores "
                .concat(calculatePercentage(promoters, TOTAL_PERSON_VOTES)));

        calculatePromotersAgeAverage(promoters);
    }

    private static PersonVote buildPersonVote(int score, int age) {
        return PersonVote.builder()
                .withAge(age)
                .withScore(score)
                .build();
    }

    private static String calculatePercentage(List<PersonVote> personVotes, int totalPerson) {
        validate(totalPerson <= 0, "No one went to the movies!");

        double votesPercent = ((double) personVotes.size() / totalPerson) * 100.0;

        return String.valueOf(votesPercent).concat(" %");
    }

    private static void calculatePromotersAgeAverage(List<PersonVote> personVotes) {
        validate(personVotes.isEmpty(), "There were no promoters!");

        var average = personVotes
                .stream()
                .map(PersonVote::getAge)
                .reduce(0, Integer::sum) / personVotes.size();

        System.out.println("Média da idade dos Promotores "
                .concat(String.valueOf(average)));
    }

    private static void validate(boolean invalidExpression, String message) {
        if (TRUE.equals(invalidExpression))
            throw new BusinnesException(message);
    }
}
