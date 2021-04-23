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

bool isInvalidInput(int iNoOfPeople, int iNoOfBackOut, float fCostOfParty) {
  bool valid = false;

  if (iNoOfPeople == 0 || iNoOfPeople < 0) {
    valid = true;
  }
  if (fCostOfParty == 0 || fCostOfParty < 0) {
    valid = true;
  }
  if (iNoOfBackOut > iNoOfPeople) {
    valid = true;
  }
  return valid;
}

float computeContribution(float fCostOfParty, int iNoOfPeople) {
  float fContribution;

  fContribution = fCostOfParty / iNoOfPeople;
  printf("\n\nOriginal contribution per person: %.2f", fContribution);
  return fContribution;
}

float computeAddedCont(float fContribution, int iNoOfBackOut, int iNoOfPeople) {
  float fAddedCont;
  fAddedCont = fContribution * iNoOfBackOut / (iNoOfPeople - iNoOfBackOut);
  return fAddedCont;
}

float computeRecomp(float fContribution, float fAddedCont) {
  float fRecomputed;
  fRecomputed = fContribution + fAddedCont;
  return fRecomputed;
}

int main() {
  int iNoOfPeople = getNoOfPeople();
  float fCostOfParty = getTotalCost();
  int iNoOfBackOut = getNumBackOut();
  float fRecomputed;

  if (isInvalidInput(iNoOfPeople, iNoOfBackOut, fCostOfParty)) {
    printf("\n\nINVALID INPUT!");
  } else {
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
  }
  return 0;
}
