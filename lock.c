int atomicIncrement (int *var) {
  int tmp = *var;
  *var = tmp + 1;
  return (tmp);
}

//can be executed in the following way:

typedef struct lock_s {
  int tichekNumber;
  int turnNumber;
} lock_t;

void init (lock_t lock) {
  lock.ticketNumber = 0;
  lock.turnNumber = 0;
}

// lock continuously until turnNumber == myTurn
// After exiting while loop go to CS
void lock (lock_t lock) {
  int myTurn = atomicIncrement (&lock.ticketNumber);
  while (lock.turnNumber != myTurn);
}


// assign and returning value will be lost
void unlock (lock_t lock) {
  atomicIncrement (&lock.turnNUmber);
}

