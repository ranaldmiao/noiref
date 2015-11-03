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
        <li class="active">
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
        <h1>Math</h1>
        <p>Number Theory</p>
        <p>Modulo Arithmetic</p>
      </div>
    </div>

    <div class="container bs-docs-container">

      <div class="row">
        <div class="col-md-9" role="main">
<!-- Primes ================================================== -->
<div class="bs-docs-section">
  <h1 id="primes" class="page-header">Primes</h1>
  <p>If you not have already known, primes are numbers that have only 2 unique factors (1 and itself). All negative numbers, 0 and 1 are not considered primes.</p>
  
  <h3 id="primes-trial">Trial Division</h3>
  <p>Given a number X, tell me whether its a prime or not.</p>
  <p>One way this could be solved is using trial division up to (and including) the square root of the number. This method yields a complexity of O(sqrt(X)) per check.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/trialdivision.cpp")); ?></pre>
  <div class="bs-callout bs-callout-warning">
    <h4>Why use <code>i &le; x/i</code>?</h4>
    <p><code>i &le; x/i</code> = <code>i*i &le; x</code> = <code>i &le; sqrt(x)</code>
    <p>Since the sqrt function in cmath is O(log(x)), using it in the loop will yield a complexity of O(sqrt(X) * log(X)) which is considerably slower.</p>
    <p><code>i*i &le; x</code> is not used since <code>i*i</code> has the tendency to overflow especially for larger numbers.</p>
  </div>
  
  <h3 id="primes-miller">Miller Rabin</h3>
  <p>When you are asked to check whether X is a prime, and X is very large, trial division will take a long time.</p>
  <p>There is an alternative method called miller rabin which will enable you to check for primes very fast (can be taken to be O(1)).</p>
  <p>The code is under-construction. Please check back later.</p>
  <!--pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/millerrabin.cpp")); ?></pre-->

  
  <h3 id="primes-sieve">Sieve of Eratosthenes</h3>
  <p>Sieve of Eratosthenes is a quick way of generating primes up to a number N. The time complexity is about O(N log N).</p>
  <p>It starts off by assuming every integer above 1 are primes. For each prime found, it will set multiples of the prime to be non-prime.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/sieve.cpp")); ?></pre>
  <p>Is there anyway to speed up the above code if the list of primes is not required?</p>
  
  <h3 id="primes-factorization">Prime Factorization</h3>
  <p>To effectively factorize numbers, you will need a sorted list of primes up to the square root of that number.</p>
  <p>For a number X, the algorithm runs in a time proportional to the number of primes below its square root. (excluding generation of the prime list).</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/primefactorization.cpp")); ?></pre>
</div>

<!-- Gretest Common Divisor =================================================== -->
<div class="bs-docs-section">
  <h1 id="gcd" class="page-header">Greatest Common Divisor</h1>
  <p>The greatest common divisor (GCD) of two numbers is the largest integer that can divide the two numbers without any remaider.</p>
  
  <h3 id="gcd-euclidean">Euclidean Algorithm</h3>
  <p>We can calculate the GCD of two numbers efficiently using Euclidean Algorithm. This algorithm runs in O(log<sub>10</sub>(X)) where X is the larger of the two numbers. The proof for this algorithm is quite long and it is recommended that you just memorize the following function:</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/gcd.cpp")); ?></pre>
  
  <h3 id="gcd-prime">Common Prime Factors</h3>
  <p>Another way to calculate GCD is to first calculate the prime factors of the two numbers. By multiplying the prime factors in common, the GCD of the both numbers will be obtained.</p>
  <p>The utilization of the below function is bounded by the time complexity of the prime factorization. This is slower than the euclidean algorithm but this might be the only way to calcualte GCD for larger numbers that do not fit into the range of long long.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/gcdprime.cpp")); ?></pre>
  
  <p>The below code computes the GCD of the two numbers (up to 1million) repeatly, utilizing the above library codes.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/gcdall.cpp")); ?></pre>
  
  <h3 id="gcd-lcm">Lowest Common Multiple</h3>
  <p>To calculate the lowest common multple (lcm) between two numbers, we can utilize the greatest common divisor of the two numbers. To be more precise lcm(a, b) = a*b/gcd(a, b)</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/lcm.cpp")); ?></pre>
</div>

<!-- Modular Arithmetic ================================================== -->
<div class="bs-docs-section">
  <h1 id="mod" class="page-header">Modular Arithmetic</h1>
  <p>Problem setters usually ask for you to print the "answer mod M" when the answer overflows the limits of int/long long. Hence, it is important to know how to utilize such restrictions and compute your answer.</p> 
  
  <h3 id="mod-basic">Basic Modular Arithmetic Operations</h3>
  <p>We can add, multiply and subtract remainders normally as the following equations are true.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/basicmod.cpp")); ?></pre>
  <p>Hence, for questions asking for "answer mod M", it is sufficient to just calculate the "intermediate answer mod M" for your intermediate steps to avoid overflow.</p>
  <p>Subtraction requires an additional + M before doing the final mod as (B % M) might be larger than (A % M), which will yield a negative number when mod M. Hence, to keep the result positive, we need to add M to the subtraction of (A % M) by (B % M).</p>

  <h3 id="mod-division">Modular Division</h3>
  <p>However, it is not possible to just divide (A % M) by (B % M) and expect to obtain (A/B) % M. Instead, if B is sufficiently small, we can calculate (A % BM) in all our intermediate steps and then output (A % BM)/B instead.</p>
  <p>Another method would be to try to cancel the greatest common divisor of both A and B before trying to do modular arithmetic. This is possible if A and B can be converted to a list of prime factors instead of dealing with the raw numerical integer value.</p>
  <p>Code for this section is omitted as it is rarely the intention of the problem setter to make contestants fret over modular division instead of the real problem. Perhaps there might be another way to approach the question without modular division.</p>
</div>

<!-- Quick Exponentiation ================================================== -->
<div class="bs-docs-section">
  <h1 id="qexp" class="page-header">Quick Exponentiation</h1>
  <p>Quick Exponentiation is the technique of using divide and conquer to raise the power of something quickly. In general, to raise something to a power of X, the complexity of the operation is O(log X), which is significantly faster than naive multiplication which will take O(X). The basic idea of quick exponentiation is that squaring a power requires O(1). For example, one can compute 13<sup>8</sup> by squaring 13 a total of 3 times. (Eg: 13<sup>8</sup> = ((13<sup>2</sup>)<sup>2</sup>)<sup>2 )</sup></p>
  
  <h3 id="qexp-int">Integer Exponentiation</h3>
  <p>When asked to compute A<sup>B</sup> mod M and M fits into the range of a 32-bit signed integer, the following code can be used.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/qexpint.cpp")); ?></pre>
  
  <h3 id="qexp-longlong">Long Long Exponentiation</h3>
  <p>However, when asked to compute A<sup>B</sup> mod M and M fits into the range of a 64-bit signed integer, the above code cannot be used.</p>
  <p>Instead, if M*2 still fits within the range of a 64-bit signed integer (Eg: M &le; 10<sup>18</sup>), quick exponentiation is still possible without big integer.</p>
  <p>To do so, we will compute X * Y mod M using divide and conquer as well, using 'qmult'.</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/qexplonglong.cpp")); ?></pre>
  
  <h3 id="qexp-matrix">Matrix Exponentiation</h3>
  <p>Quick exponentiation can also be applied to matrix as well. The Xth fibonacci can be computed quickly by exponentiating the 2x2 matrix: { {1, 1}, {1, 0} }. This matrix also co-incidentally represents { {Fib 2, Fib 1}, {Fib 1, Fib 0} } and multiplying { {Fib 2, Fib 1}, {Fib 1, Fib 0} } with { {1, 1}, {1, 0} } it results in { {Fib 3, Fib 2}, {Fib 2, Fib 1} }.</p>
  <p>In general { {1, 1}, {1, 0} } <sup>X</sup> will result in { {Fib X+1, Fib X}, {Fib X, Fib X-1} }</p>
  <p>The following code illustrates the fibonacci matrix exponentiation and is an accepted solution for mrJudge problem, fibo_ex</p>
  <pre class="lang-cpp prettyprint"><?php echo htmlentities(file_get_contents("cpp/fiboex.cpp")); ?></pre>

</div>

    
    </div>
        <div class="col-md-3">
          <div class="bs-sidebar hidden-print" role="complementary">
            <ul class="nav bs-sidenav">
              
<li>
  <a href="#primes">Primes</a>
  <ul class="nav">
    <li><a href="#primes-trial">Trial Division</a></li>
    <li><a href="#primes-miller">Miller Rabin</a></li>
    <li><a href="#primes-sieve">Sieve of Eratosthenes</a></li>
    <li><a href="#primes-factorization">Prime Factorization</a></li>
  </ul>
</li>
<li>
  <a href="#gcd">Greatest Common Divisor</a>
  <ul class="nav">
    <li><a href="#gcd-euclidean">Euclidean Algorithm</a></li>
    <li><a href="#gcd-prime">Common Prime Factors</a></li>
    <li><a href="#gcd-lcm">Lowest Common Multiple</a></li>
  </ul>
</li>

<li>
  <a href="#mod">Modular Arithmetic</a>
  <ul class="nav">
    <li><a href="#mod-basic">Basic Modular Arithmetic Operations</a></li>
    <li><a href="#mod-division">Modular Division</a></li>
  </ul>
</li>
<li>
  <a href="#qexp">Quick Exponentiation</a>
  <ul class="nav">
    <li><a href="#qexp-int">Integer Exponentiation</a></li>
    <li><a href="#qexp-longlong">Long Long Exponentiation</a></li>
    <li><a href="#qexp-matrix">Matrix Exponentiation</a></li>
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
