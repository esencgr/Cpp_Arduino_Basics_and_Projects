void setup(){
    Serial.begin( 9600 );
}

void loop(){
  
// str1.startsWith( str2 ) --> if the head of str1 is containes str2 --> return 1 - else --> return 0..
// str1.endWith( str2 ) --> if the end of str1 is containes str2 --> return 1 - else --> return 0..
// str1.startsWith( str2, indice ) --> if the str1 is containes str2 from this indice --> return 1 - else --> return 0..

    String str1 = "Strings With ARDUINO.. ";
    Serial.print( "Str1 : " );
    Serial.println( str1 );
    
    if( str1.startsWith( "Strings" ))
        Serial.println( "Str1 is starting -Strings- " );
    
    String str2 = "string and  arduino"; 
    Serial.print( "Str2 : " );
    Serial.println( str2 );
    if( str2.startsWith( "arduino", 10 ))
        Serial.println( "-arduino- is finding in the str2" );
    
    Serial.println( );

    int num1 = 12, num2 = 15;
    String str3 = " Integer value = ";
    str3 = str3 + num2;
    Serial.print( "Str3 :" );
    Serial.println( str3  );

    if ( str3.endsWith( "5" ) || str3.endsWith( "0" ) )
       Serial.println( "divide with 5.." );
    else 
       Serial.println( "not divide with 5.." );
       
    Serial.println( );
    
// str.Substring( indices_value ) --> this function is smash str from indices_value 
// str.Substring( indices_value_start, indices_value_end ) --> this function divides str from indices_val_start to end..

    String str4 = "Arduino string functions.";
    String temp8 = str4.substring( 8 );
    String temp8_14 = str4.substring( 8, 14 );
    
    Serial.print( "str = " );
    Serial.println( str4);
   
    Serial.print( "temp8 = " );
    Serial.println( temp8 );   
    
    Serial.print( "temp8_14 = " );
    Serial.println( temp8_14 );
    
    Serial.println( );
    
// str.toLowerCase(); --> all chr is convert to lower case..
// str.toUpperCase(); --> all chr is convert to upper case.. 
  
    String str5 = "ArDuIno is BEAUTIFUL.";
    Serial.println( str5);
    str5.toLowerCase();    
    Serial.println( str5 );
    str5.toUpperCase();    
    Serial.println( str5 );
    
    Serial.println( );
    
// str.toLowerCase(); --> this functions fills in the blank  
  
    String str6 = "         ArDuIno is BEAUTIFUL.        ";
    Serial.println( str6 );
    str6.trim();    
    Serial.println( str6 );
    
    Serial.println( );

// str.indexOf( 'c' ); --> this functions returns the c char's indice number in the string. 
// str.indexOf( 'c', first_indices + 1  ); --> this functions returns the second c char's indice number in the string. 

    String str7 = "Arduino is easy and powerfull!!!...>>";
    Serial.println( str7 );
    int num_in  = str7.indexOf( 'o' );
    Serial.println( num_in );
    int num_sec_in  = str7.indexOf( 'o', num_in + 1 );
    Serial.println( num_sec_in );
    
    Serial.println( );
    
// str.replace('','');  --> this functions changes first character in the brackets to second characters in the brackets  

    String str8 = "Arduino is easy and powerfull!!!...>>>";
    Serial.println( str8 );
    str8.replace( '!','<');
    Serial.println( str8 );
    Serial.println( );
    while( 1 );    
}
