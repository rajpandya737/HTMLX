# HTMLX

## About

HTMLX is a programming tool that allows you to write Python code inside of HTML files. Currently in development.

## How to Write HTMLX

HTMLX is written in HTML files. The syntax is the same as HTML, but using the <python> tag, you can write Python code. Here is an example of a simple HTMLX file:

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <python>
for i in range(10):
    print(f"<p>{i}</p>")
    </python>
</head>
</html>
```

The resultant code will be:

```html
<!DOCTYPE html>
<html lang="en">
<head>
<p>0</p>
<p>1</p>
<p>2</p>
<p>3</p>
<p>4</p>
<p>5</p>
<p>6</p>
<p>7</p>
<p>8</p>
<p>9</p>
</head>
</html>
```

## Currently Supported Features
Only basic Python code inside of the <python> tag is supported. 

Currently the program just runs whatever is inside the <python> tag and replaces the tag with the output, but in the future, this program will use its own basic python interpreter, won't rely on print() statements to generate html, allow for input variables, and more.

## How to use

Download the latest executable from the releases page. Run the executable and pass the path to the HTMLX executable as an argument. The program will then compile the HTMLX file into a normal HTML file.

## Future Plans

- [ ] Create a basic Python interpreter
- [ ] Global syntax
- [ ] Allow for input variables
- [ ] Render HTMLX files in Python using a custom library
- [ ] Better code structure and organization


