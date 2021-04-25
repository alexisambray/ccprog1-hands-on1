#include <stdbool.h>
#include <stdio.h>

int getNoOfPeople(void) {
  int iNoOfPeople;
  printf("Enter no. of people in the group: ");
  scanf("%d", &iNoOfPeople);

  return iNoOfPeople;
}

float getTotalCost(void) {
  float fCostOfParty;
  printf("Enter total cost of the party: ");
  scanf("%f", &fCostOfParty);

  return fCostOfParty;
}

int getNumBackOut(void) {
  int iNoOfBackOut;
  printf("Number of people backing out: ");
  scanf("%d", &iNoOfBackOut);

  return iNoOfBackOut;
}

bool isValidInput(int iNoOfPeople, int iNoOfBackOut, float fCostOfParty) {
  bool valid = true;

  if (iNoOfPeople <= 0) {
    valid = false;
  }
  if (fCostOfParty <= 0) {
    valid = false;
  }
  if (iNoOfBackOut > iNoOfPeople) {
    valid = false;
  }
  return valid;
}

float computeContribution(float fCostOfParty, int iNoOfPeople) {
  float fContribution = fCostOfParty / iNoOfPeople;
  printf("\n\nOriginal contribution per person: %.2f", fContribution);
  return fContribution;
}

float computeAddedCont(float fContribution, int iNoOfBackOut, int iNoOfPeople) {
  float fAddedCont =
      fContribution * iNoOfBackOut / (iNoOfPeople - iNoOfBackOut);
  return fAddedCont;
}

float computeRecomp(float fContribution, float fAddedCont) {
  float fRecomputed = fContribution + fAddedCont;
  return fRecomputed;
}

int main() {
  int iNoOfPeople = getNoOfPeople();
  float fCostOfParty = getTotalCost();
  int iNoOfBackOut = getNumBackOut();
  float fRecomputed;

  if (isValidInput(iNoOfPeople, iNoOfBackOut, fCostOfParty)) {
    float fContribution = computeContribution(fCostOfParty, iNoOfPeople);
    float fAddedCont =
        computeAddedCont(fContribution, iNoOfBackOut, iNoOfPeople);

    if (iNoOfPeople != iNoOfBackOut) {
      printf("\nAdded contribution per person due to backout: %.2f",
             fAddedCont);
    } else {
      printf("\nAdded contribution per person due to backout: 0.00");
    }

    float fRecomputed = computeRecomp(fContribution, fAddedCont);

    if (iNoOfPeople != iNoOfBackOut) {
      printf("\nRecomputed contribution per person: %.2f", fRecomputed);
    } else {
      printf("\nRecomputed contribution per person: 0.00");
    }
  } else {
    printf("\n\nINVALID INPUT!");
  }
  return 0;
}
