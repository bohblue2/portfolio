from pymilvus import Collection, CollectionSchema, DataType, FieldSchema

from dataclasses import dataclass
import os
from typing import Any, List, Optional
from pymilvus import Collection, CollectionSchema, DataType, FieldSchema, MilvusClient, utility
from hufsthon.constant import DEFAULT_EMBEDDING_DIM, MILVUS_METRIC_TYPE, MILVUS_NLIST, MILVUS_NPROBE, MILVUS_TOP_K, MILVUS_INDEX_TYPE
from pymilvus import connections

def get_client() -> MilvusClient:   
    client = MilvusClient(uri=os.getenv("MILVUS_URI"), token=os.getenv("MILVUS_API_KEY"))
    connections.connect(uri=os.getenv("MILVUS_URI"), token=os.getenv("MILVUS_API_KEY"))
    return client

def get_consultation_collection() -> Collection:
    fields = [
        FieldSchema(name="doc_id", dtype=DataType.INT64, is_primary=True),
        FieldSchema(name="content", dtype=DataType.VARCHAR, max_length=20000),
        FieldSchema(name="content_embedding", dtype=DataType.FLOAT_VECTOR, dim=DEFAULT_EMBEDDING_DIM),
        FieldSchema(name="created_at", dtype=DataType.VARCHAR, max_length=30),
        FieldSchema(name="modified_at", dtype=DataType.VARCHAR, max_length=30),
    ]
    schema = CollectionSchema(
        fields=fields, 
        description="Schema for storing consultation/counseling data embeddings"
    )
    collection = Collection(
        name="consultation_cases",
        schema=schema,
        description="Collection for storing and retrieving consultation/counseling records and their embeddings"
    )
    return collection

def create_index(collection: Collection, wait_for_building:bool=True) -> None:
    collection.create_index(
        field_name="content_embedding", 
        index_params={
            "metric_type": MILVUS_METRIC_TYPE,
            "index_type": MILVUS_INDEX_TYPE,
            "params": { "nlist": MILVUS_NLIST }
        }
    )
    if wait_for_building:
        utility.wait_for_index_building_complete(
            collection.name, 
            index_name="content_embedding"
        )
