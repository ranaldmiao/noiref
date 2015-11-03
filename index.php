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
<link href="/css/cover.css" rel="stylesheet">
<!--[if lt IE 9]><script src="../assets/js/ie8-responsive-file-warning.js"></script><![endif]-->

<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
  <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
<![endif]-->




  </head>
  <body>
    <a class="sr-only" href="#content">Skip to main content</a>

    <!-- Docs master nav -->
    <header class="navbar navbar-fixed bs-docs-nav" role="banner">
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
        <li>
          <a href="/ds/">Data Structure</a>
        </li>
      </ul>
    </nav>
  </div>
</header>


    <div class="site-wrapper">

      <div class="site-wrapper-inner">

        <div class="cover-container">


          <div class="inner cover">
            <h1 class="cover-heading">NOI Reference</h1>
            <p class="lead">A collection of algorithms &amp; data structures maintained by Ranald Lam.</p>
            <p class="lead">Meant for circulation among Raffles Institution Programming Members only.</p>
            <p>
                <a href="/misc/">Misc.</a>&middot;
                <a href="/math/">Math</a>&middot;
                <a href="/dp/">Dynamic Programming</a>&middot;
                <a href="/graph/">Graph</a>&middot;
                <a href="/ds/">Data Structure</a>
            </p>
            <p>Copyrighted 2014. All rights reserved.</p>
            <p>Site page views: <?php echo file_get_contents("counter.txt"); ?></p>
          </div>

        </div>

      </div>

    </div>


<!-- Bootstrap core JavaScript
================================================== -->
<!-- Placed at the end of the document so the pages load faster -->
<script src="/js/jquery.min.js"></script>
<script src="/js/bootstrap.min.js"></script>
<script src="/js/docs.min.js"></script>



  </body>
</html>
<?php $counter = intval(file_get_contents("counter.txt")); file_put_contents("counter.txt", $counter+1); ?>
