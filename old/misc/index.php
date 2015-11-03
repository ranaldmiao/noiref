<!DOCTYPE html>
<html lang="en">
  <head>
    <!-- Meta, title, CSS, favicons, etc. -->
    <meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">

<title>
    NOI Reference
</title>

<!-- Bootstrap core CSS -->
<link href="/css/bootstrap.min.css" rel="stylesheet">

<!-- Documentation extras -->
<link href="/css/docs.min.css" rel="stylesheet">
<link href="/css/prettify.css" rel="stylesheet">
<link href="/css/app.css" rel="stylesheet">
<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
  <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
<![endif]-->



  </head>
  <body>
    <a class="sr-only" href="#content">Skip to main content</a>

    <!-- Docs master nav -->
    <header class="navbar navbar-static-top bs-docs-nav" role="banner">
  <div class="container">
    <div class="navbar-header">
      <button class="navbar-toggle" type="button" data-toggle="collapse" data-target=".bs-navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <a href="/" class="navbar-brand">NOI Reference</a>
    </div>
    <nav class="collapse navbar-collapse bs-navbar-collapse" role="navigation">
      <ul class="nav navbar-nav">
        <li class="active">
          <a href="/misc/">Misc.</a>
        </li>
        <li>
          <a href="/math/">Math</a>
        </li>
        <li>
          <a href="/dp/">Dynamic Programming</a>
        </li>
        <li>
          <a href="/graph/">Graph</a>
        </li>
        <li>
          <a href="/ds/">Data Structure</a>
        </li>
      </ul>
    </nav>
  </div>
</header>


    <!-- Docs page layout -->
    <div class="bs-header" id="content">
      <div class="container">
        <h1>Misc</h1>
        <p>Tips</p>
        <p>Bit manipulation, Bit-masking</p>
        
      </div>
    </div>

    <div class="container bs-docs-container">

      <div class="row">
        <div class="col-md-9" role="main">
<!-- Tips ================================================== -->
<div class="bs-docs-section">
  <h1 id="tips" class="page-header">Tips</h1>

  
  <h3 id="tips-header">Header Files</h3>
  <p>Instead of including multiple header files, there is a nice header file that will automatically include all other header files: bits/stdc++.h</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/header.cpp")); ?></pre>
  <p>If the above fails to compile (on older compilers), here is the list of commonly used header files.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/allheaders.cpp")); ?></pre>


  
  <h3 id="tips-define">Define</h3>
  <p>Using <code>#define</code> can save you time coding and debugging. It also makes your code look neater.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/define.cpp")); ?></pre>
  
  <h3 id="tips-iterators">Iterators</h3>
  <p>Using iterators might be of a hassle, but it also decreases the complexity of your code, making debugging easier and faster. It is also easier to read. Compare the following two codes when iterating the vector <code>adjList[x]</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/iterator.cpp")); ?></pre>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/noiterator.cpp")); ?></pre>
  
  
  <h3 id="tips-typedef">Typedef</h3>
  <p>In the previous section, you might have realised that <code>vector< pair<int, int> >::iterator</code> might have been a lot to type. You can use <code>typedef</code> to reduce the hassle.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/typedef.cpp")); ?></pre>
  
  <h3 id="tips-typeof">Typeof</h3>
  <p>You may also want to use <code>typeof</code> to let the compiler decipher what is the variable type.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/typeof.cpp")); ?></pre>
</div>
<!-- Bit Manipulation ================================================== -->
<div class="bs-docs-section">
  <h1 id="bits" class="page-header">Bit Manipulation</h1>
  <p>Computers represent data in the form of bits. As such, bit operators tend to be faster than arithmetic operations and can speed up your code!</p> 

  
  <h3 id="bits-basic">Basic Operations</h3>
  <p>We can manipulate the bits of an integer using several bitwise operations.</p>
  <p><b>AND</b> will return 1 when both bits are 1</p>
  <p><b>OR</b> will return 1 if either of the bits are 1</p>
  <p><b>XOR</b> will return 1 if the bits are different</p>
  <p><b>LEFT</b> PUSH X will push all the bits to the left by X positions (Same as dividing by 2<sup>X</sup>)</p>
  <p><b>RIGHT</b> PUSH X will push all the bits to the right by X positions (Same as multiplying by 2<sup>X</sup>)</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/basicbits.cpp")); ?></pre>

  <h3 id="bits-bitmask">Bitmask</h3>
  <p>For some problems, the state involves storing whether certain items are taken or not. For example: out of item 0 to 5, item 0, 2 and 5 are taken. To do that, we can employ the bit representations of integers to store them efficiently. This technique is called bitmask or bitmasking.</p>
  <p>Let the 0th item be represented by the first bit, 1st item by the second bit.. and so on.</p>
  <p>You will realise that for the <b>Xth</b> bit, it is represented by the bit that is '1' in the binary representation of <b>2<sup>X</sup></b> or <code>1&lt;&lt;X</code>
  <p>Lets say you have a bitmask (integer) of base 2: <code>000101</code>. It means that items 0 and 2 are taken (hence the first bit and the 3rd bit is 1).</p>
  <p>To check if an item is taken, we check if the corresponding bit is '1' using bitwise <b>AND</b>.</p>
  <p>To denote that an item is taken, we simply change the corresponding bit to '1' and vice-versa if the item is untaken. To do so, we can toggle the bit from '0' to '1' or '1' to '0' using bitwise <b>XOR</b></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/bitmask.cpp")); ?></pre>
  <div class="bs-callout bs-callout-info">
    <h4>Shortcuts</h4>
    <p>To set the first X items to be taken, you can do <code>bitmask = (1&lt;&lt;X)-1</code></p>
    <p>To always set the Xth item to be taken (even if it is already taken), you can do <code>bitmask = bitmask | (1&lt;&lt;X)</code></p>
    <p>To always set the Xth item to be not taken (even if it is already not taken), you can do <code>bitmask = bitmask &amp; (~(1&lt;&lt;X))</code></p>

  </div>
</div>
    </div>
        <div class="col-md-3">
          <div class="bs-sidebar hidden-print" role="complementary">
            <ul class="nav bs-sidenav">
              
<li>
  <a href="#tips">Tips</a>
  <ul class="nav">
    <li><a href="#tips-header">Header Files</a></li>
    <li><a href="#tips-define">Define</a></li>
    <li><a href="#tips-iterators">Iterators</a></li>
    <li><a href="#tips-typedef">Typedef</a></li>
    <li><a href="#tips-typeof">Typeof</a></li>
  </ul>
</li>

<li>
  <a href="#bits">Bit Manipulation</a>
  <ul class="nav">
    <li><a href="#bits-basic">Basic Operations</a></li>
    <li><a href="#bits-bitmask">Bitmask</a></li>
  </ul>
</li>



              
            </ul>
          </div>
        </div>
      </div>

    </div>

    <!-- Footer
================================================== -->
<footer class="bs-footer" role="contentinfo">
  <div class="container">
    <p>Code compiled and written by Ranald Lam.</p>
    <p>Copyrighted 2014. All rights reserved.</p>
    <p>Limited distribution among Raffles Institution students only.</p>
  </div>
</footer>

<!-- Bootstrap core JavaScript
================================================== -->
<!-- Placed at the end of the document so the pages load faster -->
<script src="/js/jquery.min.js"></script>
<script src="/js/bootstrap.min.js"></script>
<script src="/js/docs.min.js"></script>
<script src="/js/prettify.js"></script>
<script src="/js/app.js"></script>

  </body>
</html>
