All: q1 

1 : question_1.c
        gcc -pthread $? -o $@


clean :
        @find . -type f -executable -exec rm -fr {} \;
