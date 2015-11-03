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
        <li>
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
        <li class="active">
          <a href="/ds/">Data Structure</a>
        </li>
      </ul>
    </nav>
  </div>
</header>


    <!-- Docs page layout -->
    <div class="bs-header" id="content">
      <div class="container">
        <h1>Dynamic Programming</h1>
        <p>Classic DP Problems</p>
        
      </div>
    </div>

    <div class="container bs-docs-container">

      <div class="row">
        <div class="col-md-9" role="main">
<!-- Static Range Sum Query ================================================== -->
<div class="bs-docs-section">
  <h1 id="rsq" class="page-header">Static Range Sum Query</h1>
  <p>For (significantly) easy computation and shorter code, the library below is for <b>1-indexed</b> sum queries.</p>
  <p>You should convert your code to 1-indexed (in input) before using the library code.</p>
  <h3 id="rsq-1d">1D Static Range Sum Query</h3>
  <p>Do note that the below code is 1-indexed. (The original array must be 1-indexed too) <code>rsq(x, y)</code> is inclusive of x and y.</p>
  <p>The code stores the sum in <code>sum</code>. Please declare it to be long long if sum of the initial array will overflow integer.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/1drsq.cpp")); ?></pre>
  
  <h3 id="rsq-2d">2D Static Range Sum Query</h3>
  <p>Do note that the below code is 1-indexed. (The original array must be 1-indexed too) <code>rsq(x1, y1, x2, y2)</code> is inclusive of (x1, y1) and (x2, y2).</p>
  <p>The code stores the sum in <code>sum</code>. Please declare it to be long long if sum of the initial array will overflow integer.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/2drsq.cpp")); ?></pre>

  <h3 id="rsq-3d">3D Static Range Sum Query</h3>
  <p>Do note that the below code is 1-indexed. (The original array must be 1-indexed too) <code>rsq(x1, y1, z1, x2, y2, z2)</code> is inclusive of (x1, y1, z1) and (x2, y2, z2).</p>
  <p>The code stores the sum in <code>sum</code>. Please declare it to be long long if sum of the initial array will overflow integer.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/3drsq.cpp")); ?></pre>
</div>

<!-- Max Sum ================================================== -->
<div class="bs-docs-section">
  <h1 id="maxsum" class="page-header">Max Sum</h1>
  
  <h3 id="maxsum-1d">1D Max Sum</h3>
  <p>Original array is <code>arr</code> and answer is stored at <code>ans</code>. The below algorithm will still give the correct answer when the numbers in the array are negative.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/1dmaxsum.cpp")); ?></pre>
  
  <h3 id="maxsum-2d">2D Max Sum</h3>
  <p><b>The below code is from Hubert's NOI Reference.</b></p>
  <p>Array <code>m[i][j]</code> stores value in cell (i, j).</p>
  <p>Array <code>sum[i][j]</code> stores sum of cells in the rectangle, whose top-left point is (0, 0) and bottom-right point (i, j).</p>
  <p>Array <code>dp[r1][c1][r2][c2]</code> stores sum of cells in the rectangle, whose top-left point is (r1, c1) and bottom-right point (r2, c2).</p>
  <p>Maximum score can be found in integer mx.</p>
  <p>O(n^3) runtime can also be achieved by performing the 1D maxsum on the columns of all O(n^2) consecutive set of rows.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/2dmaxsum_hubert.cpp")); ?></pre>
</div>


<!-- Longest Increasing Subsequence ================================================== -->
<div class="bs-docs-section">
  <h1 id="lis" class="page-header">Longest Increasing Subsequence</h1>
  <p>The below code assumes that they are strictly increasing. To calculate longest decreasing subsequence, reverse the array then run the below codes.</p>
  <h3 id="lis-n2">N<sup>2</sup> LIS</h3>
  <p>Original array is <code>a</code> and answer is stored at <code>ans</code>.</p>
  <p><code>dp[x]</code> stores the length of the LIS that ends with <code>a[x]</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/lis_N2.cpp")); ?></pre>
  <h3 id="lis-nlogn">N log N LIS</h3>
  <p>Original array is <code>a</code> and answer is stored at <code>l</code>. The array <code>h</code> is for speed up purposes.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/lis_NlogN.cpp")); ?></pre>
 
</div>

<!-- Coin Change Ways ================================================== -->
<div class="bs-docs-section">
  <h1 id="ccways" class="page-header">Coin Change Ways</h1>
  
  <h3 id="ccways-bottom">Bottom Up</h3>
  <p><code>V</code> is the value to express in coins.</p>
  <p><code>C</code> is the number of coins and <code>coin[i]</code> stores the value of the i<sup>th</sup> coin (0 &le; i &lt; C)</p>
  <p>This solution does not count repeated number of ways: Eg. 1+1+5 is considered the same way as 1+5+1. However, the code assumes that the coin values are unique (no repeated values)</p>
  <p>Answer is found at <code>dp[V]</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/ccways_bottom.cpp")); ?></pre>
  
  
  <h3 id="ccways-top">Top Down</h3>
  <p><code>V</code> is the value to express in coins.</p>
  <p><code>C</code> is the number of coins and <code>coin[i]</code> stores the value of the i<sup>th</sup> coin (0 &le; i &lt; C)</p>
  <p>This solution does not count repeated number of ways: Eg. 1+1+5 is considered the same way as 1+5+1. However, the code assumes that the coin values are unique (no repeated values)</p>
  <p>Answer is found by calling <code>r(V, C-1)</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/ccways_top.cpp")); ?></pre>
  
</div>

<!-- Coin Change Minimum ================================================== -->
<div class="bs-docs-section">
  <h1 id="ccmin" class="page-header">Coin Change Minimum</h1>
  
  <h3 id="ccmin-bottom">Bottom Up</h3>
  <p><code>V</code> is the value to express in coins.</p>
  <p><code>C</code> is the number of coins and <code>coin[i]</code> stores the value of the i<sup>th</sup> coin (0 &le; i &lt; C)</p>
  <p>This code assumes that you can repeatedly use the same coin and a value of "-1" means there is no way to express that value in the given set of coins. (Although this method may be longer, it has less chance of WA due to low values of 'infinity')</p>
  <p>Answer is found at <code>dp[V]</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/ccmin_bottom.cpp")); ?></pre>
  
  
  <h3 id="ccmin-top">Top Down</h3>
  <p><code>V</code> is the value to express in coins.</p>
  <p><code>C</code> is the number of coins and <code>coin[i]</code> stores the value of the i<sup>th</sup> coin (0 &le; i &lt; C)</p>
  <p>This solution does not count repeated number of ways: Eg. 1+1+5 is considered the same way as 1+5+1. However, the code assumes that the coin values are unique (no repeated values)</p>
  <p>Answer is found by calling <code>r(V, C-1)</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/ccmin_top.cpp")); ?></pre>
  
</div>

<!-- Knapsack ================================================== -->
<div class="bs-docs-section">
  <h1 id="knapsack" class="page-header">Knapsack</h1>
  
  <h3 id="knapsack-bottom">Bottom Up</h3>
  <p><code>M</code> is the maximum total size of items the bag can hold.</p>
  <p><code>N</code> is the number of items and <code>v[i]</code> stores the value of the i<sup>th</sup> item and <code>s[i]</code> stores the size of the i<sup>th</sup> item (0 &le; i &lt; N)</p>
  <p>Answer is found at <code>ans</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/knapsack_bottom.cpp")); ?></pre>
  
  
  <h3 id="knapsack-top">Top Down</h3>
  <p><code>M</code> is the maximum total size of items the bag can hold.</p>
  <p><code>N</code> is the number of items and <code>v[i]</code> stores the value of the i<sup>th</sup> item and <code>s[i]</code> stores the size of the i<sup>th</sup> item (0 &le; i &lt; N)</p>
  <p>Answer is found by calling <code>r(M, N-1)</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/knapsack_top.cpp")); ?></pre>
</div>

<!-- Longest Common Subsequence ================================================== -->
<div class="bs-docs-section">
  <h1 id="lcs" class="page-header">Longest Common Subsequence</h1>
  
  <h3 id="lcs-bottom">Bottom Up</h3>
  <p><code>a</code> and <code>b</code> are the 2 strings (char array) and <code>lena</code> and <code>lenb</code> are their corresponding lengths.</p>
  <p>Answer is found in <code>dp[lena][lenb]</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/lcs_bottom.cpp")); ?></pre>
  
  
  <h3 id="lcs-top">Top Down</h3>
  <p><code>a</code> and <code>b</code> are the 2 strings (char array).</p>
  <p>Answer is found by calling <code>lcs(strlen(a), strlen(b))</code></p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/lcs_top.cpp")); ?></pre>
</div>

<!-- Cutting Sticks ================================================== -->
<div class="bs-docs-section">
  <h1 id="sticks" class="page-header">Cutting Sticks</h1>
  
  <h3 id="sticks-n3">N<sup>3</sup> Cutting Sticks</h3>
  <p>Original array is <code>a</code> and answer is stored at <code>dp[0][N-1]</code>.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/cuttingsticks_N3.cpp")); ?></pre>
  <h3 id="sticks-n2">N<sup>2</sup> Cutting Sticks</h3>
  <p>Original array is <code>a</code> and answer is stored at <code>dp[0][N-1]</code>. Code utilizes Knuth Yao algorithm for DP speedup.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/cuttingsticks_N2.cpp")); ?></pre>
 
</div>
    </div>
        <div class="col-md-3">
          <div class="bs-sidebar hidden-print" role="complementary">
            <ul class="nav bs-sidenav">
              
<li>
  <a href="#rsq">Static Range Sum Query</a>
  <ul class="nav">
    <li><a href="#rsq-1d">1D Static Range Sum Query</a></li>
    <li><a href="#rsq-2d">2D Static Range Sum Query</a></li>
    <li><a href="#rsq-3d">3D Static Range Sum Query</a></li>
  </ul>
</li>

<li>
  <a href="#maxsum">Max Sum</a>
  <ul class="nav">
    <li><a href="#maxsum-1d">1D Max Sum</a></li>
    <li><a href="#maxsum-2d">2D Max Sum</a></li>
  </ul>
</li>
<li>
  <a href="#lis">Longest Increasing Subsequence</a>
  <ul class="nav">
    <li><a href="#lis-n2">N<sup>2</sup> LIS</a></li>
    <li><a href="#lis-nlogn">N log N LIS</a></li>
  </ul>
</li>
<li>
  <a href="#ccways">Coin Change Ways</a>
  <ul class="nav">
    <li><a href="#ccways-bottom">Bottom Up</a></li>
    <li><a href="#ccways-top">Top Down</a></li>
  </ul>
</li>
<li>
  <a href="#ccmin">Coin Change Minimum</a>
  <ul class="nav">
    <li><a href="#ccmin-bottom">Bottom Up</a></li>
    <li><a href="#ccmin-top">Top Down</a></li>
  </ul>
</li>
<li>
  <a href="#knapsack">Knapsack</a>
  <ul class="nav">
    <li><a href="#knapsack-bottom">Bottom Up</a></li>
    <li><a href="#knapsack-top">Top Down</a></li>
  </ul>
</li>
<li>
  <a href="#lcs">Longest Common Subsequence</a>
  <ul class="nav">
    <li><a href="#lcs-bottom">Bottom Up</a></li>
    <li><a href="#lcs-top">Top Down</a></li>
  </ul>
</li>
<li>
  <a href="#sticks">Cutting Sticks</a>
  <ul class="nav">
    <li><a href="#sticks-n3">N<sup>3</sup> Cutting Sticks</a></li>
    <li><a href="#sticks-n2">N<sup>2</sup> Cutting Sticks</a></li>
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
    <p>Site page views: <?php echo file_get_contents("../counter.txt"); ?></p>

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
<?php $counter = intval(file_get_contents("../counter.txt")); file_put_contents("../counter.txt", $counter+1); ?>

