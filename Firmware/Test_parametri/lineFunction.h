

  String generateIDMachinery()
  {
    String id = "";

    id = machineries[random(0, 6)];
    return id;
  }

//*************************************************************************************************

 String generateIDProduct()
  {
    String id = "";

    id = products[random(0, 7)];
    return id;
  }

//*************************************************************************************************

  int generateErrorCode()
    {
      int code;
  
      code = errorCodes[random(0, 12)];
      return code;
    }

//*************************************************************************************************

