#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = "yourSSID";
char pass[] = "yourPASSWORD";
int status = WL_IDLE_STATUS;

void setup()
{
    Serial.begin(9600);

    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        status = WiFi.begin(ssid, pass);
        delay(10000);
    }
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;

        http.begin("http://your-server-ip-or-domain/api/createMachine.php");

        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        String postData = "machineName=testMachine&machineIp=192.168.1.100&errLeftCnt=0&errRightCnt=0&errBrushCnt=0&errControllerCnt=0&prmLeftRampUp=50&prmLeftRampDown=50&prmLeftMinSpeed=50&prmLeftMaxSpeed=50&prmRightRampUp=50&prmRightRampDown=50&prmRightMinSpeed=50&prmRightMaxSpeed=50&prmBrushRampUp=50&prmBrushRampDown=50&prmBrushMinSpeed=50&prmBrushMaxSpeed=50&prmJyMiddleVal=50&prmJyDeadZone=50&prmJoyMinVal=50&prmJoyMaxVal=50&prmPotMinVal=50&prmPotMaxVal=50";

        int httpResponseCode = http.POST(postData);

        if (httpResponseCode > 0)
        {
            String response = http.getString();
            Serial.println("Server response: " + response);
        }
        else
        {
            Serial.print("HTTP POST request failed, error: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    }

    delay(5000);
}
