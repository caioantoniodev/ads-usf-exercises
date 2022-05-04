package main.entity;

public class PersonVote {
    private Integer age;
    private Integer score;

    public Integer getAge() {
        return age;
    }

    public Integer getScore() {
        return score;
    }

    public static Builder builder() {
        return new Builder();
    }

    public static final class Builder {
        private Integer age;
        private Integer score;

        public Builder withAge(Integer age) {
            this.age = age;
            return this;
        }

        public Builder withScore(Integer score) {
            this.score = score;
            return this;
        }

        public PersonVote build() {
            PersonVote personVote = new PersonVote();
            personVote.age = this.age;
            personVote.score = this.score;
            return personVote;
        }
    }

    @Override
    public String toString() {
        return "PersonVote{" +
                "age=" + age +
                ", score=" + score +
                '}';
    }
}
