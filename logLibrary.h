//
// Created by Piotr Krzyszowski.
//

//Errors
#define openingFileError "Error while opening file:"
#define creatingFIFOError "Error while creating FIFO queue"
#define findingQueueKeyError "Error while finding queue key!"
#define openingMessageQueueError "Error while opening message queue"
#define sendingMessageQueueError "Error while sending the message"
#define openingFIFOError "Error while opening FIFO queue"
#define readingFIFOError "Error while reading from FIFO queue"
#define receivingMessageError "Error while receiving a message"
#define creatingQueueError "Error while creating queue"
#define forkingProcessError "Error while forking process"

//Info
#define exit "EXIT\n"
#define wrongInput "Wrong input!\n"
#define inputMessage "\nReceiver: %s,\nCommand: %s,\nResponse FIFO queue: %s.\n\n",
#define fifoAnswer "\nFIFO answer: \n%s\n"
#define startingReceiver "Receiver Start\n Command: %s\n"
#define finished "Receiver Finished\n\n"
#define wrongProcessNumber "The program was given wrong number of arguments!\nPlease provide only one process name!\n"
#define createdQueueId "Created queue ID: %d\n\n"