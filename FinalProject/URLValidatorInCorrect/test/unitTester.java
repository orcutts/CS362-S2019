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
public class unitTester extends TestCase {



public void testUnitTest()
{
	String[] tester = null;
	
	 UrlValidator urlVal = new UrlValidator(tester, UrlValidator.ALLOW_ALL_SCHEMES);
	
	//Check if urlValidator works for known passing and failing Urls
	assert(urlVal.isValid("http://www.google.com"));
	assertFalse(urlVal.isValid("http:/www.google.com"));
	assertFalse(urlVal.isValid("http://.go.a1a.org/#"));
	
	//build URLs to test 
	for (int i = 0; i < 7;i++)
	{
		urlVal = new UrlValidator(tester, UrlValidator.ALLOW_ALL_SCHEMES);
		
		assert(urlVal.isValidAuthority(urlBuilder[i+7]));
		
		assert(urlVal.isValidPath(urlBuilder[i+21]));
		
		assert(urlVal.isValidQuery(urlBuilder[i+28]));
		
		String url= urlBuilder[i]+urlBuilder[i+7]+urlBuilder[i+14]+urlBuilder[i+21]+urlBuilder[i+28];
		assert(urlVal.isValid(url));
	
	}
	
	 //Check known list of passing and failing urls
	for (int i = 0; i < passingUrls.length; i ++)
	{
		
		assert(urlVal.isValid(passingUrls[i]));
		
	}
	for (int i = 0; i < failingUrls.length; i ++)
	{
		
		assertFalse(urlVal.isValid(failingUrls[i]));
		
	}
	
	
	 
}


String passingUrls[] ={
		
		"http://www.google.com",
		"http://www.youtube.com",
		"http://www.facebook.com",
		"http://www.amazon.com",
		"mad://www.twitter.com",
		
		
		"htTp://www.ebay.com",
		"gopher://www.instagram.com",
		"https://www.wikipedia.com",
		"go://www.reddit.com",
		"h3t://www.bing.edu",
		
		
		"http://www.craigslist.com",
		"http://www.indeed.com",
		"http://www.pinterest.com",
		"http://www.chase.com",
		"hTTp://www.zillow.com",
		
		
		"http://eee.msn.com:100",
		"http://www.netflix.com:65",
		"gopher://www.linkedin.com:900",
		"http://www.paypal.com:30000",
		"http://www.accuweather.com:000",
		
		
		"http://www.espn.com/test",
		"http://www.imdb.com/:",
		"hTTTTp://www.imgur.com/:80",
		"http://www.yelp.com/test1/test2/?",
		"go://www.mlb.com/test1/test2/test3/test4/test5",
		
		
		"mad://www.wellsfargo.com ",
		"http://www.homedepot.com?",
		"http://www.target.com????",
		"https://www.walmart.com?page=this&page",
		
		
		
};
String failingUrls[]=
{
		"http:/www.google.com",
		"://www.youtube.com",
		"3ht://www.facebook.com",
		"www.amazon.com",
		"/www.twitter.com",
		
		
		"htTp://www.go.....com",
		"gopher://www.instagram.abcdefghijklmn'\'opqrstuvwxyz.com",
		"https://www..com",
		"go://www. .com",
		"h3t://www.//.com",
		
		
		"http://www.craigslist.com____",
		"http://www.indeed.com:-0000",
		"http://www.pinterest.com:123456789987654321",
		"http://www.chase.com:1x",
		"http://www.zillow.com:  :",
		
		
		"http://www.msn.com:100//",
		"http://www.netflix.com:65./_",
		"http://www.linkedin.com:900!",
		"http://www.paypal.com:30000///////////////////",
		"http://www.accuweather.com:000test",
		
		
		"http://www.espn.com!/test!",
		"http://www.imdb.com/{S}/()",
		"http://www.imgur.com/:80/test//",
		"http://www.yelp.com/test1/test2/^",
		"http://www.mlb.go/fail",
		
		
		"http://www.wellsfargo.com / =?wrongQuery",
		"http://www.homedepot.com*",
		"http://www.target.comtest/?=YouShallNotPass",
		"http://www.walmart.com@?page=this&page_#?%",



};

String urlBuilder[]=
{
		"http://",
		"https://",
		"h3t://",
		"gopher://",
		"url://",
		"thisPage://",
		"h3t://",
		
		"www.urlOne.com",
		"www.aaa.com",
		"www.com.gov",
		"www.government.gov",
		"eee.school.edu",
		"www.website.co",
		"www.email.com",
		
		":100",
		":0",
		":",
		"/:",
		":9999",
		":1",
		":0000000",

		"/",
		"/test1/test2",
		"/??",
		"/123456789",
		"",
		"/././././././",
		"",
		
		"?=thisPage",
		"#?=",
		"?queryOne?",
		"?/?/?/?/?",
		"?=!",
		"??????",
		""
};
		

}