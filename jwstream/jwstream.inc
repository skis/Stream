<?php
function getMediaFilePath($nid = 0) {
  $query = 'SELECT fm.filename FROM {node} n INNER JOIN {file_usage} fu ON fu.id = n.nid AND n.nid = :nid
    INNER JOIN {file_managed} fm ON fm.fid = fu.fid';

  $result = db_query($query, array(':nid' => $nid));
  $filename = $result->fetchObject()->filename;
  return $filename;
}
