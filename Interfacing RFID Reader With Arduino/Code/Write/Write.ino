#include <SPI.h>      //include the SPI library
#include <MFRC522.h>  //include the MFRC522 RFID reader library

#define RST_PIN 9  //reset pin, which can be changed to another digital pin if needed.
#define SS_PIN 10  //SS or the slave select pin, which can be changed to another digital pin if needed.

MFRC522 mfrc522(SS_PIN, RST_PIN);  // create a MFRC522 instant.
MFRC522::MIFARE_Key key;          //create a MIFARE_Key struct named 'key' to hold the card information

byte data1[14] = {"Circuit-Digest"};  //The first data that needs to be written to the tag.
byte data2[12] = {"Jobit-Joseph"};  //The second data that needs to be written to the tag.
byte readbackblock[18];  //Array for reading out a block.

void setup()
{
  Serial.begin(115200);        // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
  Serial.println("Scan a MIFARE Classic card");

  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;  // Prepare the security key for the read and write operations.
  }
}

void loop()
{
  // Look for new cards if not found rerun the loop function
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // read from the card if not found rerun the loop function
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.println("card detected. Writing data");
  writeBlock(1, data1); //write data1 to the block 1 of the tag
  writeBlock(2, data2); //write data2 to the block 2 of the tag

  Serial.println("reading data from the tag");
  readBlock(1, readbackblock);   //read block 1
  //print data
  Serial.print("read block 1: ");
  for (int j = 0 ; j < 14 ; j++)
  {
    Serial.write (readbackblock[j]);
  }
  Serial.println("");
  readBlock(2, readbackblock);  //read block 2
  //print data
  Serial.print("read block 2: ");
  for (int j = 0 ; j < 12 ; j++)
  {
    Serial.write (readbackblock[j]);
  }
  Serial.println("");

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));//uncomment below line if want to see the entire memory dump.


}



//Write specific block
int writeBlock(int blockNumber, byte arrayAddress[])
{
  //check if the block number corresponds to data block or triler block, rtuen with error if it's trailer block.
  int largestModulo4Number = blockNumber / 4 * 4;
  int trailerBlock = largestModulo4Number + 3; //determine trailer block for the sector
  if (blockNumber > 2 && (blockNumber + 1) % 4 == 0) {
    Serial.print(blockNumber);
    Serial.println(" is a trailer block: Error");
    return 2;
  }
  

  //authentication
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Authentication failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return 3;//return "3" as error message
  }

  //writing data to the block
  status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);
  //status = mfrc522.MIFARE_Write(9, value1Block, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Data write failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return 4;//return "4" as error message
  }
  Serial.print("Data written to block ");
  Serial.println(blockNumber);
}



//Read specific block
int readBlock(int blockNumber, byte arrayAddress[])
{
  int largestModulo4Number = blockNumber / 4 * 4;
  int trailerBlock = largestModulo4Number + 3; //determine trailer block for the sector

  //authentication of the desired block for access
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {
    Serial.print("Authentication failed : ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return 3;//return "3" as error message
  }

  //reading data from the block
  byte buffersize = 18;
  status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);//&buffersize is a pointer to the buffersize variable; MIFARE_Read requires a pointer instead of just a number
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Data read failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return 4;//return "4" as error message
  }
  Serial.println("Data read successfully");
}
