gcc credit.c -o credit

printf '378282246310005' | ./credit # AMEX
printf '371449635398431' | ./credit # AMEX
printf '378734493671000' | ./credit # AMEX
printf '5555555555554444' | ./credit # MASTERCARD
printf '5105105105105100' | ./credit # MASTERCARD
printf '4111111111111111' | ./credit # VISA
printf '4012888888881881' | ./credit # VISA
printf '4222222222222' | ./credit # VISA
printf '4999991111111113' | ./credit # VISA
printf '4999992222222229' | ./credit # VISA
printf '5199999999999991' | ./credit # MASTERCARD
printf '5299999999999990' | ./credit # MASTERCARD
printf '748394738988437' | ./credit # INVALID

rm credit
