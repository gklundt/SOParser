#!/usr/env/perl
use strict;
use warnings;

use Carp;
use Data::Dump;
use DBI;
use Test::More;

my $databaseFile = 'db/KWIC.db';

if ( ! -e $databaseFile ) {
	croak "$databaseFile file not found!";
}

my $dbh = DBI->connect("dbi:SQLite:dbname=db/KWIC.db");

sub insert {
	my ($string, $url) = @_;
	my $sth = $dbh->prepare("insert into KWIC(string,url) VALUES (?,?)");
	$sth->execute($string,$url);
}

sub search {
	my @searchValues = @_;
	my $sth = $dbh->prepare('select * from KWIC');
	$sth->execute;
	my $data = $sth->fetchall_hashref('stringID');
	return $data;
}

insert("Unversity of Central Oklahoma",'http://uco.edu');
my $data = search();

is_deeply($data->{1},
	{
		string => "Unversity of Central Oklahoma",
		stringID => 1,
		url => "http://uco.edu",
	}
);

done_testing();
