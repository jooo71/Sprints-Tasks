/*
 * card.h
 *
 *  Created on: Aug 15, 2023
 *      Author: PC
 */

#ifndef CARD_H_
#define CARD_H_

typedef unsigned char uint8_t;
typedef char int8_t;

typedef struct ST_cardData_t
{
     uint8_t cardHolderName[25];
     uint8_t primaryAccountNumber[20];
     uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
     CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
#define Null 1

void getCardHolderNameTest(void);
void getCardExpiryDateTest (void);
void getCardPANTest (void);

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);

#endif /* CARD_H_ */
