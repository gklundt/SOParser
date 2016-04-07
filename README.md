# SOParser
Various KWIC Implementations

#### /insert
	Description: Inserts new entries into database
	Method: POST
	Inputs: JSON Array, each object containing two properties, 
	string and url.
	Response: JSON Array, each object containing two properties, pstring and purl. Response 
	          will be a circular shifted version of the input

#### /search
	Description: Searches for specified strings
	Method: POST
	Inputs: JSON Array of strings
	Response: JSON string
	
#### /clear
	Description: Clear the database
	Method: POST
	Inputs: JSON string 
	Response: JSON string, OK or FAIL
