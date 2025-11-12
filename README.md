# HW11-XMLParser

# Overview
In this assignment, you will implement a recursive XML parser in C that extracts book titles from an XML file and displays them in alphabetical order. The parser should handle various edge cases including malformed XML, empty files, and files without title tags.

# XML File Example
    <library>
        <book>
            <title>The Great Gatsby</title>
            <author>F. Scott Fitzgerald</author>
            <year>1925</year>
        </book>
        <book>
            <title>To Kill a Mockingbird</title>
            <author>Harper Lee</author>
            <year>1960</year>
        </book>
        <book>
            <title>1984</title>
            <author>George Orw1ell</author>
            <year>1949</year>
        </book>
    </library>

# Output Example
    1. 1984
    2. The Great Gatsby
    3. To Kill a Mockingbird

# Learning Objectives
1) Practice recursive algorithm design <br />
2) Implement string manipulation in C <br />
3) Handle file I/O operations <br />
4) Work with command-line arguments <br />

# Function Specifications
1) char* read_xml_file(const char* filename) <br />
    Opens and reads the contents of an XML file <br />
    Returns a dynamically allocated string with file content <br />
    Handles file errors and empty files appropriately <br />
    Caller must free the returned memory <br /> <br />

2) void find_titles_recursive(const char *xml)<br />
    Recursively searches for <title> tags in XML content <br />
    Extracts text content between title tags <br />
    Handles malformed XML gracefully (nested tags, missing closing tags) <br />
    Stores found titles in the global titles array <br /> <br />

3) void sort_titles_alphabetically() <br />
    Sorts the collected titles in alphabetical order using qsort <br />
    Case-sensitive sorting <br /> <br />
   
5) void print_titles() <br />
    Prints sorted titles in numbered format to stdout <br />
    Format: [number]. [title] <br />

# Submission Instructions
Submit the hw11.c file after filling out the following functions: <br />
  read_xml_file(const char* filename) <br />
  find_titles_recursive(const char *xml) <br />
  sort_titles_alphabetically() <br />
  print_titles() <br />
