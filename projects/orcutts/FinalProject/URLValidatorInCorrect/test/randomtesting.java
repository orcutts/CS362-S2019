/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import junit.framework.TestCase;
//import org.junit.Test;
//import java.util.Random;


public class randomtesting extends TestCase {
	
  public void testRandomIsValid()
   {
	// Valid strings 
    String[] validschemes = {"http://","ftp://","h3t://"}; 
	String[] validauths = {"www.com","www.amazon.com","0.0.0.0","amazon.com:80"}; 
	String[] validpaths = {"","/test1/file","/t123","/$23"}; 
	String[] validqueries = {"","?action=hide","?action=hide&mode=up"}; 
	
	
	// Invalid strings
	String[] invalidschemes = {"3ht://", "http:/", "http:"}; 
	String[] invalidauths = {"256.256.256.256","am.3n","go.a1a","amazon.com:jh"}; 
	String[] invalidpaths = {"/..","/../","/..//file","/test1//file"}; 


	System.out.println("-----Start random testing - valid combinations-----");

	//long randomseed = 10; 
	//Random random = new Random(randomseed);
	for(int i = 0; i < 1000; i++)
	{
		// create urlVal so that we can run isValid on the random string that is built
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		int randomScheme = (int )(Math.random() * 3 + 0); // 4 options 
		int randomAuth = (int )(Math.random() * 4 + 0); // 4 options 
		int randomPath = (int )(Math.random() * 4 + 0); // 4 options
		int randomQuery = (int )(Math.random() * 3 + 0); // 3 options
		
		// Build random Url
		String temp = validschemes[randomScheme] + validauths[randomAuth] + validpaths[randomPath] + validqueries[randomQuery];
		assert(urlVal.isValid(temp));
	}
	
	System.out.println("-----Done random testing - valid combinations-----");
	System.out.println("---------------------------------------------------------------------------");
	System.out.println("-----Start random testing - invalid combinations-----");

	//random = new Random(randomseed);
	for(int i = 0; i < 1000; i++)
	{
		// create urlVal so that we can run isValid on the random string that is built
		//UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
		int randomScheme = (int )(Math.random() * 3 + 0); // 4 options 
		int randomAuth = (int )(Math.random() * 4 + 0); // 4 options 
		int randomPath = (int )(Math.random() * 4 + 0); // 4 options
		
		// Build random Url
		String temp = validschemes[randomScheme] + validauths[randomAuth] + validpaths[randomPath];
		assert(urlVal.isValid(temp));
	
	}	
	System.out.println("-----Done random testing - invalid combinations-----");
	System.out.println("---------------------------------------------------------------------------");
	System.out.println("-----Start random testing - randomly invalid combinations-----");

	//random = new Random(randomseed);
	for(int i = 0; i < 1000; i++)
	{
		// create urlVal so that we can run isValid on the random string that is built
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		int randomScheme = (int )(Math.random() * 3 + 0); // 4 options 
		int randomAuth = (int )(Math.random() * 4 + 0); // 4 options 
		int randomPath = (int )(Math.random() * 4 + 0); // 4 options
		
		// Build randomly invalid Url
		// Randomly select which part of url is invalid
		int randomselect = (int )(Math.random() * 3 + 0);
		if (randomselect == 0) 
		{
			String temp = invalidschemes[randomScheme] + validauths[randomAuth] + validpaths[randomPath];
			assertFalse(urlVal.isValid(temp));
		} 
		else if (randomselect == 1) 
		{
			String temp = validschemes[randomScheme] + invalidauths[randomAuth] + validpaths[randomPath];
			assertFalse(urlVal.isValid(temp));
		}
		else if (randomselect == 2) 
		{
			String temp = validschemes[randomScheme] + validauths[randomAuth] + invalidpaths[randomPath];
			assertFalse(urlVal.isValid(temp));
		}
	
	}	
	System.out.println("-----Done random testing - randomly invalid combinations-----");
	
  }
  
}