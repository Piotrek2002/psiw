//
// Created by Piotr Krzyszowski.
//

//Errors
#define openingFileError "Error while opening file:"
#define creatingFIFOError "Error while creating FIFO"
#define findingQueueKeyError "Error while finding queue key!"
#define openingMessageQueueError "Error while opening message queue"
#define sendingMessageQueueError "Error while sending the message"
#define openingFIFOError "Error while opening FIFO"
#define readingFIFOError "Error while reading from FIFO"
#define receivingMessageError "Error while receiving a message"
#define creatingQueueError "Error while creating queue"
#define forkingProcessError "Error while forking process"

//Info
#define exit "exit\n"
#define wrongInput "Wrong input!\n"
#define inputMessage "\nReceiver: %s,\nCommand: %s,\nResponse FIFO: %s.\n\n",
#define fifoAnswer "\nFIFO answer: \n%s\n"
#define startingReceiver "RECEIVER START\nCommand: %s\n"
#define wrongProcessNumber "The program was given wrong number of arguments!\nPlease provide only one process name!\n"
#define createdQueueId "Created queue ID: %d\n\n"
#define requestInfo "Please provide \"exit\" or input in format:\nProcess \"commandToExecute\" \"answerFifo\"\n$ "
#define processNotFound "Process not found!\n"
#define wrongProcessName "Wrong process name!\n"
#define queueKey "Queue key: %d\n"
#define argumentsNumber "Argument %d : %s\n"
#define newLine "\n"

//Scan
#define scanLine "%[^\n]s"
#define ignoreScan "%*c"