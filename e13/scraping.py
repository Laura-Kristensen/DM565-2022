import requests
import re
from bs4 import BeautifulSoup

page = requests.get("https://imada.sdu.dk/~kslarsen/dm565/E04.php")
soup = BeautifulSoup(page.content, "lxml")

def is_file_link(href):
    return href and re.compile("^Files/").search(href)

print("--- FILES ---")
for t in soup.find_all(href=re.compile("^Files/")):
    print( t )

# ol > li > ol > li:nth-child(2)

for li in soup("li"):
    if li("ol"):
        print( "--- EXERCISE ---" )
        print( li )

for li in soup("li"):
    parent = li.parent
    if parent.name == "ol" and parent.find_parent("ol"):
        print( "--- SUBQUESTION ---")
        print( li )


for li in soup("li"):
    if li("ol"):
        print( "--- 2. QUESTION ---" )
        print( li.ol("li")[1] )

#content > ol > li:nth-child(5) > ol > li:nth-child(2)

for string in soup.find_all(string=re.compile("Using")):
    if string.parent.name == "li":
        print( "--- LI TAG ---" )
        print( string.parent )



for code in soup("code"):
    print( "--- CODE ---")
    print( code.string )
