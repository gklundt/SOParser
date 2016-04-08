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
	my @regex = @_;
	my @searchValues = @_;
	my $sth = $dbh->prepare('select * from KWIC');
	$sth->execute;
	my $data = $sth->fetchall_arrayref({});

	my @results;
	ROW:
	for (@{$data}) {
		for my $reg (@regex) {
			my $matched = $_->{string} =~ /$reg/i ? 1 : 0;
			next ROW if (!$matched);
		}
		push @results,$_->{url};
	}
	return join ' ',@results;
}

my $sth = $dbh->prepare('delete from KWIC');
$sth->execute();

insert("Unversity of Central Oklahoma",'http://uco.edu');
insert("Unversity of Oklahoma",'http://ou.edu');

my $data = search('central');
is($data,'http://uco.edu',"UCO url matches for search for central");

$data = search('central oklahoma');
is($data,'http://uco.edu',"UCO url matches for search for central and oklahoma");

$data = search('central oklahoma dog ');
isnt($data,'http://uco.edu',"no match for central oklahoma and dog");

$data = search('oklahoma');
is($data,'http://uco.edu http://ou.edu', "ou and uco for oklahoma");

done_testing();
