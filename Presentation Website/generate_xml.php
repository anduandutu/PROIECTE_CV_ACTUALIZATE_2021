<?php
// Include config file
require_once "config.php";

$result_aticles = $mysqli->query("SELECT Post_ID, Post_Title FROM posts WHERE Post_Type = 'article'");
$result_blogs = $mysqli->query("SELECT Post_ID, Post_Title FROM posts WHERE Post_Type = 'blog'");
$result_products = $mysqli->query("SELECT P_name FROM products");
$results_forums = $mysqli->query("SELECT ID_Forum,Forum_Subject FROM forums");

$xml = new DOMDocument("1.0");
$xml->formatOutput=true;

$links = $xml->createElement("links");

$xml->appendChild($links);

while($row = mysqli_fetch_array($result_aticles)){

	$link = $xml->createElement("link");
	$links->appendChild($link);

	$title = $xml->createElement("title",$row['Post_Title']);
	$url = $xml->createElement("url","http://localhost/website_silent_knight_games/view_article_full_post.php?post_no=".$row['Post_ID']);

	$link->appendChild($title);
	$link->appendChild($url);
}

while($row = mysqli_fetch_array($result_blogs)){

	$link = $xml->createElement("link");
	$links->appendChild($link);

	$title = $xml->createElement("title",$row['Post_Title']);
	$url = $xml->createElement("url","http://localhost/website_silent_knight_games/view_article_full_post.php?post_no=".$row['Post_ID']);

	$link->appendChild($title);
	$link->appendChild($url);
}
while($row = mysqli_fetch_array($result_products)){

	$link = $xml->createElement("link");
	$links->appendChild($link);

	$title = $xml->createElement("title",$row['P_name']);
	$url = $xml->createElement("url","http://localhost/website_silent_knight_games/view_product.php?varname=".$row['P_name']);

	$link->appendChild($title);
	$link->appendChild($url);
}

while($row = mysqli_fetch_array($results_forums)){

	$link = $xml->createElement("link");
	$links->appendChild($link);

	$title = $xml->createElement("title",$row['Forum_Subject']);
	$url = $xml->createElement("url","http://localhost/website_silent_knight_games/view_forum_interventions.php?forum_no=".$row['ID_Forum']);

	$link->appendChild($title);
	$link->appendChild($url);
}

$xml->save("links.xml");
?>