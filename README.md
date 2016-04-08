# SOParser
Various KWIC Implementations

#### /insert
	Description: Inserts new entries into database
	Method: POST
	Inputs: JSON Array, each object containing two properties, 
	string and url.
	Response: JSON Array, each object containing two properties, pstring and purl. Response 
	          will be a circular shifted version of the input

	Example: 
		Client sends: 
	[
		{
		"string":"University of Central Oklahoma",
		"url": "http://uco.edu"
		},{
		"string":"University of Oklahoma",
		"url":"http://ou.edu"
		}
	]

	Will Receive back:
	[
	  {
		"purl": "http://uco.edu",
		"pstring": "Central Oklahoma University of "
	  },
	  {
		"pstring": "Oklahoma University of Central ",
		"purl": "http://uco.edu"
	  },
	  {
		"pstring": "University of Central Oklahoma ",
		"purl": "http://uco.edu"
	  },
	  {
		"pstring": "Oklahoma University of ",
		"purl": "http://ou.edu"
	  },
	  {
		"purl": "http://ou.edu",
		"pstring": "University of Oklahoma "
	  }
	]
    
									    

#### /search
	Description: Searches for specified strings
	Method: POST
	Inputs: JSON Array of strings
	Response: JSON string

	Example:

	Client sends: 
	[ "Central", "Oklahoma" ]
	Receives back:
	"http://uco.edu"

	
#### /clear
	Description: Clear the database
	Method: POST
	Inputs: JSON string 
	Response: JSON string, OK or FAIL
