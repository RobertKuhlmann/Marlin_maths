/* ========================================================================== */
/*                                                                            */
/*   new_mathematics test-code                                                */
/*                                                                            */
/*                                                                            */
/*   Description                                                              */
/*   Insert this into Marlin_main.cpp to test the new mathematical            */
/*   functions with GCode M998 on your ATmega                                 */
/* ========================================================================== */

    case 998: //M998 Test accuracy and measure math-speed
    {
      float saveresult;
      MarlinSerial ms;
      SERIAL_ECHOLN("Performing Math-tests...");
      
      SERIAL_ECHOLN("  1. Accuracy");
      SERIAL_ECHOLN("  1.1 SQRT(float)   float;fsqrt;sqrt");
      for (int i=1; i <= 1000; i++)
      {
        saveresult = (float)i/10;
        SERIAL_ECHO("    ");
        ms.printFloat(saveresult,8);
        SERIAL_ECHO(";");
        ms.printFloat(fsqrt(saveresult),8);
        SERIAL_ECHO(";");
        ms.printFloat(sqrt(saveresult),8);
        SERIAL_ECHOLN("");
      }
      SERIAL_ECHOLN("  1.2 fsin(deg)   deg;fsin;sin");
      for (int i=1; i <= 3600; i++)
      {
        float actdeg = (float)i/10;
        SERIAL_ECHO("    SIN(");
        ms.printFloat(actdeg,8);
        SERIAL_ECHO(");");
        ms.printFloat(fsin(actdeg),8);
        SERIAL_ECHO(";");
        ms.printFloat(sin(actdeg/SCARA_RAD2DEG),8);
        SERIAL_ECHOLN("");
      }
      SERIAL_ECHOLN("  1.3 fcos(deg)   deg;fcos;cos");
      for (int i=1; i <= 3600; i++)
      {
        float actdeg = (float)i/10;
        SERIAL_ECHO("    COS(");
        ms.printFloat(actdeg,8);
        SERIAL_ECHO(");");
        ms.printFloat(fcos(actdeg),8);
        SERIAL_ECHO(";");
        ms.printFloat(cos(actdeg/SCARA_RAD2DEG),8);
        SERIAL_ECHOLN("");
      }
      SERIAL_ECHOLN("  1.4 ftan(deg)   deg;ftan;tan");
      for (int i=1; i <= 3600; i++)
      {
        float actdeg = (float)i/10;
        SERIAL_ECHO("    TAN(");
        ms.printFloat(actdeg,8);
        SERIAL_ECHO(");");
        ms.printFloat(ftan(actdeg),8);
        SERIAL_ECHO(";");
        ms.printFloat(tan(actdeg/SCARA_RAD2DEG),8);
        SERIAL_ECHOLN("");
      }
      SERIAL_ECHOLN("  2. Performance");
      SERIAL_ECHOLN("  2.1 SQRT(float) 10000 times   fsqrt s;sqrt s");
      float starttime1=millis();
      for (int i=0; i <= 10000; i++)
      {
        saveresult += fsqrt((float)i/100);
      }
      float stoptime1=millis();
      float starttime2=millis();
      for (int i=0; i <= 10000; i++)
      {
        saveresult += sqrt((float)i/100);
      }
      float stoptime2=millis();
      SERIAL_ECHO("    ");
      ms.printFloat((stoptime1-starttime1)/1000,8);
      SERIAL_ECHO(" s;");
      ms.printFloat((stoptime2-starttime2)/1000,8);
      SERIAL_ECHOLN(" s");
      SERIAL_ECHOLN("");
      SERIAL_ECHOLN("  2.2 fsin(deg) 3600 times   fsin s;sin s");
      starttime1=millis();
      for (int i=0; i <= 3600; i++)
      {
        saveresult += fsin(((float)i/10));
      }
      stoptime1=millis();
      starttime2=millis();
      for (int i=0; i <= 3600; i++)
      {
        saveresult += sin(((float)i/10)/SCARA_RAD2DEG);
      }
      stoptime2=millis();
      SERIAL_ECHO("    ");
      ms.printFloat((stoptime1-starttime1)/1000,8);
      SERIAL_ECHO(" s;");
      ms.printFloat((stoptime2-starttime2)/1000,8);
      SERIAL_ECHOLN(" s");
      SERIAL_ECHOLN("");
      SERIAL_ECHOLN("  2.3 fcos(deg) 3600 times   fcos s;cos s");
      starttime1=millis();
      for (int i=0; i <= 3600; i++)
      {
        saveresult += fcos(((float)i/10));
      }
      stoptime1=millis();
      starttime2=millis();
      for (int i=0; i <= 3600; i++)
      {
        saveresult += cos(((float)i/10)/SCARA_RAD2DEG);
      }
      stoptime2=millis();
      SERIAL_ECHO("    ");
      ms.printFloat((stoptime1-starttime1)/1000,8);
      SERIAL_ECHO(" s;");
      ms.printFloat((stoptime2-starttime2)/1000,8);
      SERIAL_ECHOLN(" s");
      SERIAL_ECHOLN("");
      SERIAL_ECHOLN("  2.3 ftan(deg) 3600 times   ftan s;tan s");
      starttime1=millis();
      for (int i=0; i <= 3600; i++)
      {
        saveresult += ftan(((float)i/10));
      }
      stoptime1=millis();
      starttime2=millis();
      for (int i=0; i <= 3600; i++)
      {
        saveresult += tan(((float)i/10)/SCARA_RAD2DEG);
      }
      stoptime2=millis();
      SERIAL_ECHO("    ");
      ms.printFloat((stoptime1-starttime1)/1000,8);
      SERIAL_ECHO(" s;");
      ms.printFloat((stoptime2-starttime2)/1000,8);
      SERIAL_ECHOLN(" s");
    }
    break;
